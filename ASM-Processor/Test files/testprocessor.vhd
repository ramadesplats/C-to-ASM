--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:27:20 04/27/2017
-- Design Name:   
-- Module Name:   /home/ymao/Bureau/uProcesseur/testprocessor.vhd
-- Project Name:  uProcesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: pipeline
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY testprocessor IS
END testprocessor;
 
ARCHITECTURE behavior OF testprocessor IS 
 
	 -- Component Decode
	 COMPONENT decode
    PORT(
         DataIN : IN  std_logic_vector(31 downto 0);
         OP : OUT  std_logic_vector(7 downto 0);
         A : OUT  std_logic_vector(15 downto 0);
         B : OUT  std_logic_vector(15 downto 0);
         C : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
	 
    -- Component Pipe line
 
    COMPONENT pipeline
    PORT(
         CLK : IN  std_logic;
         OPIN : IN  std_logic_vector(7 downto 0);
         AIN : IN  std_logic_vector(15 downto 0);
         BIN : IN  std_logic_vector(15 downto 0);
         CIN : IN  std_logic_vector(15 downto 0);
         OPOUT : OUT  std_logic_vector(7 downto 0);
         AOUT : OUT  std_logic_vector(15 downto 0);
         BOUT : OUT  std_logic_vector(15 downto 0);
         COUT : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
	 
	 -- Component registers
	 COMPONENT regs
    PORT(
         adrA : IN  std_logic_vector(4 downto 0);
         adrB : IN  std_logic_vector(4 downto 0);
         adrW : IN  std_logic_vector(4 downto 0);
         W : IN  std_logic;
         Data : IN  std_logic_vector(15 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(15 downto 0);
         QB : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
	 
	 -- component multiplexeur
	 COMPONENT muxregs
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           QA : in  STD_LOGIC_VECTOR (15 downto 0);
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0));
	 END COMPONENT;
	 
	 -- Component UAL
	 COMPONENT ual
    PORT(
         A : IN  std_logic_vector(15 downto 0);
         B : IN  std_logic_vector(15 downto 0);
         Ctrl_Alu : IN  std_logic_vector(2 downto 0);
         N : OUT  std_logic;
         O : OUT  std_logic;
         Z : OUT  std_logic;
         C : OUT  std_logic;
         S : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
	 
	 -- Component Logic Controller UAL
	 COMPONENT lcual
    PORT(
         OP : IN  std_logic_vector(7 downto 0);
         LC_OUT : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
	 
	 -- component multiplexeur UAL
	 COMPONENT muxual
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           S : in  STD_LOGIC_VECTOR (15 downto 0);
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0));
	 END COMPONENT;
	 
	 -- Component Logic Controller a la fin
	 COMPONENT lc
    PORT(
         OP : IN  std_logic_vector(7 downto 0);
         LC_OUT : OUT  std_logic
        );
    END COMPONENT;
	
	
	-- Signaux

   --Inputs
   signal CLK : std_logic := '0';
	signal RST : std_logic := '0';
   signal DataIN : std_logic_vector(31 downto 0) := (others => '0');
	
	
	--Intermediaire
	--LI/DI
	signal LIDI_Ain : std_logic_vector(15 downto 0) := (others => '0');
	signal LIDI_Aout : std_logic_vector(15 downto 0) := (others => '0');
	signal LIDI_OPin : std_logic_vector(7 downto 0) := (others => '0');
	signal LIDI_OPout : std_logic_vector(7 downto 0) := (others => '0');
	signal LIDI_Bin : std_logic_vector(15 downto 0) := (others => '0');
	signal LIDI_Bout : std_logic_vector(15 downto 0) := (others => '0');
	signal LIDI_Cin : std_logic_vector(15 downto 0) := (others => '0');
	signal LIDI_Cout : std_logic_vector(15 downto 0) := (others => '0');
	
	--Banc de registres
	--Inputs
   signal REG_adrA : std_logic_vector(4 downto 0) := (others => '0');
   signal REG_adrB : std_logic_vector(4 downto 0) := (others => '0');
   signal REG_adrW : std_logic_vector(4 downto 0) := (others => '0');
   signal REG_W : std_logic := '0';
   signal REG_Data : std_logic_vector(15 downto 0) := (others => '0');
 	--Outputs
   signal REG_QA : std_logic_vector(15 downto 0);
   signal REG_QB : std_logic_vector(15 downto 0);
	
	-- multiplexeur apres regs
	signal MUXREGS_OP : std_logic_vector(7 downto 0) := (others => '0');
   signal MUXREGS_B : std_logic_vector(15 downto 0) := (others => '0');
   signal MUXREGS_QA : std_logic_vector(15 downto 0) := (others => '0');
   signal MUXREGS_DataOUT : std_logic_vector(15 downto 0) := (others => '0');
	
	--DI/EX
	signal DIEX_Ain : std_logic_vector(15 downto 0) := (others => '0');
	signal DIEX_Aout : std_logic_vector(15 downto 0) := (others => '0');
	signal DIEX_OPin : std_logic_vector(7 downto 0) := (others => '0');
	signal DIEX_OPout : std_logic_vector(7 downto 0) := (others => '0');
	signal DIEX_Bin : std_logic_vector(15 downto 0) := (others => '0');
	signal DIEX_Bout : std_logic_vector(15 downto 0) := (others => '0');
	signal DIEX_Cin : std_logic_vector(15 downto 0) := (others => '0');
	signal DIEX_Cout : std_logic_vector(15 downto 0) := (others => '0');
	
	-- UAL
	--Inputs
   signal UAL_A : std_logic_vector(15 downto 0) := (others => '0');
   signal UAL_B : std_logic_vector(15 downto 0) := (others => '0');
   signal UAL_Ctrl_Alu : std_logic_vector(2 downto 0) := (others => '0');
	signal UAL_CLK : std_logic;
 	--Outputs
   signal UAL_N : std_logic;
   signal UAL_O : std_logic;
   signal UAL_Z : std_logic;
   signal UAL_C : std_logic;
   signal UAL_S : std_logic_vector(15 downto 0);
	
	-- lcual
	signal LCUAL_in : std_logic_vector(7 downto 0) := (others => '0');
	signal LCUAL_out : std_logic_vector(2 downto 0) := (others => '0');
	
	-- multiplexeur ual
	signal MUXUAL_OP : std_logic_vector(7 downto 0) := (others => '0');
   signal MUXUAL_B : std_logic_vector(15 downto 0) := (others => '0');
   signal MUXUAL_S : std_logic_vector(15 downto 0) := (others => '0');
   signal MUXUAL_DataOUT : std_logic_vector(15 downto 0) := (others => '0');
	
	--EX/Mem
	signal EXMEM_Ain : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Aout : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_OPin : std_logic_vector(7 downto 0) := (others => '0');
	signal EXMEM_OPout : std_logic_vector(7 downto 0) := (others => '0');
	signal EXMEM_Bin : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Bout : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Cin : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Cout : std_logic_vector(15 downto 0) := (others => '0');
	
	--Mem/RE
	signal MEMRE_Ain : std_logic_vector(15 downto 0) := (others => '0');
	signal MEMRE_Aout : std_logic_vector(15 downto 0) := (others => '0');
	signal MEMRE_OPin : std_logic_vector(7 downto 0) := (others => '0');
	signal MEMRE_OPout : std_logic_vector(7 downto 0) := (others => '0');
	signal MEMRE_Bin : std_logic_vector(15 downto 0) := (others => '0');
	signal MEMRE_Bout : std_logic_vector(15 downto 0) := (others => '0');
	signal MEMRE_Cin : std_logic_vector(15 downto 0) := (others => '0');
	signal MEMRE_Cout : std_logic_vector(15 downto 0) := (others => '0');
	
	-- lc a la fin
	signal LCRE_in : std_logic_vector(7 downto 0) := (others => '0');
	signal LCRE_out : std_logic := '0';
	
   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
	-- decode unit
	de: decode PORT MAP (
		 DataIN => DataIN,
		 OP => LIDI_OPin,
		 A => LIDI_Ain,
		 B => LIDI_Bin,
		 C => LIDI_Cin
	  );

	-- pipeline li/di
   lidi: pipeline PORT MAP (
          CLK => CLK,
          OPIN => LIDI_OPin,
          AIN => LIDI_Ain,
          BIN => LIDI_Bin,
          CIN => LIDI_Cin,
          OPOUT => LIDI_OPout,
          AOUT => LIDI_Aout,
          BOUT => LIDI_Bout,
          COUT => LIDI_Cout
   );
	
	-- lidi to regs
	REG_adrA <= LIDI_Bout(4 downto 0);
	REG_adrB <= LIDI_Cout(4 downto 0);
	
	-- regs
	re: regs PORT MAP (
		adrA => REG_adrA,
		adrB => REG_adrB,
		adrW => REG_adrW,
		W => REG_W,
		Data => REG_Data,
		RST => RST,
		CLK => CLK,
		QA => REG_QA,
		QB => REG_QB
   );
	
	-- lidi/regs to mux
	MUXREGS_OP <= LIDI_OPout;
	MUXREGS_B <= LIDI_Bout;
	MUXREGS_QA <= REG_QA;
	
	-- mux
	muxr: muxregs PORT MAP (
		OP => MUXREGS_OP,
		B => MUXREGS_B,
		QA => MUXREGS_QA,
		DataOUT => MUXREGS_DataOUT
	);
	
	-- di
	DIEX_OPin <= LIDI_OPout;
	DIEX_Ain <= LIDI_Aout;
	DIEX_Bin <= MUXREGS_DataOUT;
	DIEX_Cin <= REG_QB;
	
	-- pipeline di/ex
	diex: pipeline PORT MAP (
          CLK => CLK,
          OPIN => DIEX_OPin,
          AIN => DIEX_Ain,
          BIN => DIEX_Bin,
          CIN => DIEX_Cin,
          OPOUT => DIEX_OPout,
          AOUT => DIEX_Aout,
          BOUT => DIEX_Bout,
          COUT => DIEX_Cout
   );
	
	-- ex
	EXMEM_OPin <= DIEX_OPout;
	EXMEM_Ain <= DIEX_Aout;
	
	-- diex to lcual
	LCUAL_in <= DIEX_OPout;
	
	-- lcual
	lcu: lcual PORT MAP (
			OP => LCUAL_in,
			LC_OUT => LCUAL_out
	);
	
	-- ex to ual
	UAL_A <= DIEX_Bout;
	UAL_B <= DIEX_Cout;
	UAL_Ctrl_Alu <= LCUAL_out;
	
	-- ual
	alu: ual PORT MAP (
		 A => UAL_A,
		 B => UAL_B,
		 Ctrl_Alu => UAL_Ctrl_Alu,
		 N => UAL_N,
		 O => UAL_O,
		 Z => UAL_Z,
		 C => UAL_C,
		 S => UAL_S
	  );
	
	-- ex to mux
	MUXUAL_OP <= DIEX_OPout;
	MUXUAL_B <= DIEX_Bout;
	MUXUAL_S <= UAL_S;
	
	-- muxual
	muxu: muxual PORT MAP (
		OP => MUXUAL_OP,
		B => MUXUAL_B,
		S => MUXUAL_S,
		DataOUT => MUXUAL_DataOUT
	);
	
	-- to exmem
	EXMEM_Bin <= MUXUAL_DataOUT;
	EXMEM_Cin <= x"0000";
	
	-- pipeline ex/mem
	exmem: pipeline PORT MAP (
          CLK => CLK,
          OPIN => EXMEM_OPin,
          AIN => EXMEM_Ain,
          BIN => EXMEM_Bin,
          CIN => EXMEM_Cin,
          OPOUT => EXMEM_OPout,
          AOUT => EXMEM_Aout,
          BOUT => EXMEM_Bout,
          COUT => EXMEM_Cout
   );
	
	-- mem
	MEMRE_OPin <= EXMEM_OPout;
	MEMRE_Ain <= EXMEM_Aout;
	MEMRE_Bin <= EXMEM_Bout;
	MEMRE_Cin <= x"0000";
	
	-- pipeline mem/re
	memre: pipeline PORT MAP (
          CLK => CLK,
          OPIN => MEMRE_OPin,
          AIN => MEMRE_Ain,
          BIN => MEMRE_Bin,
          CIN => MEMRE_Cin,
          OPOUT => MEMRE_OPout,
          AOUT => MEMRE_Aout,
          BOUT => MEMRE_Bout,
          COUT => MEMRE_Cout
   );
	
	-- mem/re to lcre
	LCRE_in <= MEMRE_OPout;
	
	-- lcre
	lcre: lc PORT MAP (
			OP => LCRE_in,
			LC_OUT => LCRE_out
	);
	
	-- lcre to regs
	REG_W <= LCRE_out;
	REG_adrW <= MEMRE_Aout(4 downto 0);
	REG_data <= MEMRE_Bout(15 downto 0);
	

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;

      -- insert stimulus here
		-- AFC
		RST <= '1';
		DataIN <= x"0601ABCD";
		wait for 100 ns;
		
		DataIN <= x"05060100";
		wait for 100 ns;
		
		DataIN <= x"01020106";
		wait for 100 ns;

      wait;
   end process;

END;

----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:51:40 05/02/2017 
-- Design Name: 
-- Module Name:    fpga - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity fpga is 
	Port ( 
			  RST : in STD_LOGIC;
			  CLK : in STD_LOGIC;
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0);
			  --VGA_vga_clk : in std_logic ;
			  --VGA_vga_rst : in std_logic;
			  VGA_vga_red : out std_logic_vector(2 downto 0);
			  VGA_vga_grn : out std_logic_vector(2 downto 0);
			  VGA_vga_blu : out std_logic_vector(1 downto 0);
			  VGA_vga_hsync : out std_logic;
			  VGA_vga_vsync : out std_logic
			  );

end fpga;

architecture Behavioral of fpga is
	-- div
	COMPONENT div
	PORT (
		  CLK : in  STD_LOGIC;
		  RST : in  STD_LOGIC;
		  CLK_2 : out  STD_LOGIC;
		  CLK_4 : out  STD_LOGIC);
	END COMPONENT;

	 -- ip
	 COMPONENT ip
    PORT(
         DIN : IN  std_logic_vector(15 downto 0);
         DOUT : OUT  std_logic_vector(15 downto 0);
         CLK : IN  std_logic;
         RST : IN  std_logic;
         LOAD : IN  std_logic;
         EN : IN  std_logic
        );
    END COMPONENT;
	 
	 -- ram 32
	 component bram32
		  generic (
			 init_file : String := "init32.hex";
			 adr_width : Integer := 11);
		  port (
		  -- System
		  sys_clk : in std_logic;
		  sys_rst : in std_logic;
		  -- Master
		  di : out std_logic_vector(31 downto 0);
		  we : in std_logic;
		  a : in std_logic_vector(15 downto 0);
		  do : in std_logic_vector(31 downto 0));
	end component;

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

	
	-- controlleur alea de donnee
	 COMPONENT ctlalea
    Port ( CLK : in STD_LOGIC;
			  lidiOPin : in  STD_LOGIC_VECTOR (7 downto 0);
           lidiBin : in  STD_LOGIC_VECTOR (15 downto 0);
           lidiCin : in  STD_LOGIC_VECTOR (15 downto 0);
           diexOPin : in  STD_LOGIC_VECTOR (7 downto 0);
           diexAin : in  STD_LOGIC_VECTOR (15 downto 0);
			  diexBin : in  STD_LOGIC_VECTOR (15 downto 0);
           exmemOPin : in  STD_LOGIC_VECTOR (7 downto 0);
           exmemAin : in  STD_LOGIC_VECTOR (15 downto 0);
           memreOPin : in  STD_LOGIC_VECTOR (7 downto 0);
           memreAin : in  STD_LOGIC_VECTOR (15 downto 0);
           ipENout : out  STD_LOGIC;
			  ipLOADout : out  STD_LOGIC;
			  ipDINout : out  STD_LOGIC_VECTOR (15 downto 0);
           lidiNOPout : out  STD_LOGIC);
	 END COMPONENT;
	
	 
    -- Component Pipe line
    COMPONENT pipeline
    PORT(
         CLK : IN  std_logic;
			NOP : IN std_logic;
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
			  Ain: in  STD_LOGIC_VECTOR (15 downto 0);
			  Aout: out  STD_LOGIC_VECTOR (15 downto 0);
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
			  N : in  std_logic;
			  Z : in  std_logic;
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0));
	 END COMPONENT;
	 
	 -- Component Logic Controller Mémoire des données
	 COMPONENT lcmem
    PORT(
         OP : IN  std_logic_vector(7 downto 0);
         LC_OUT : OUT  std_logic
        );
    END COMPONENT;
	 
	 --Memoire RAM 16 bits--
	 component bram16
		  generic (
			 init_file : String := "init16.hex";
			 adr_width : Integer := 11);
		  port (
		  -- System
		  sys_clk : in std_logic;
		  sys_rst : in std_logic;
		  -- Master
		  di : out std_logic_vector(15 downto 0);
		  we : in std_logic;
		  a : in std_logic_vector(15 downto 0);
		  do : in std_logic_vector(15 downto 0));
	 end component;
	 
	 -- VGA
	 component vga_top port (
	  -- System
	  sys_clk : in std_logic;
	  sys_rst : in std_logic;
	  -- VGA
	  vga_clk : in std_logic;
	  vga_rst : in std_logic;
	  vga_red : out std_logic_vector(2 downto 0);
	  vga_grn : out std_logic_vector(2 downto 0);
	  vga_blu : out std_logic_vector(1 downto 0);
	  vga_hsync : out std_logic;
	  vga_vsync : out std_logic;
	  -- Data bus
	  mem_dr : out std_logic_vector(15 downto 0);
	  mem_we : in std_logic;
	  mem_a : in std_logic_vector(10 downto 0);
	  mem_dw : in std_logic_vector(15 downto 0));
	end component;
	 
	 
	 -- Component Logic Controller a la fin
	 COMPONENT lc
    PORT(
         OP : IN  std_logic_vector(7 downto 0);
         LC_OUT : OUT  std_logic
        );
    END COMPONENT;
	
	
	 -- Component multiplexeur data
	 COMPONENT muxdata is
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           DATA_DI : in  STD_LOGIC_VECTOR (15 downto 0);
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0));
    END COMPONENT;
	 
	
	-- Signaux

	-- IP
   signal IP_DIN : std_logic_vector(15 downto 0) := (others => '0');
	signal IP_DOUT : std_logic_vector(15 downto 0) := (others => '0');
   signal IP_LOAD : std_logic := '0';
   signal IP_EN : std_logic;
	
	-- RAM 32 bits 
	signal RAM32_di : std_logic_vector(31 downto 0):= (others => '0');
	signal RAM32_we : std_logic;
	signal RAM32_a : std_logic_vector(15 downto 0):= (others => '0');
	signal RAM32_do : std_logic_vector(31 downto 0):= (others => '0');
	
	-- datain pour decode
	signal DataIN : std_logic_vector(31 downto 0):= (others => '0');
	
	-- controleur alea de donnee
	signal ALEA_lidiOPin : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');
	signal ALEA_lidiBin : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_lidiCin : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_diexOPin : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');
	signal ALEA_diexAin : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_diexBin : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_exmemOPin : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');
	signal ALEA_exmemAin : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_memreOPin : STD_LOGIC_VECTOR (7 downto 0):= (others => '0');
	signal ALEA_memreAin : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_ipENout : STD_LOGIC:= '0';
	signal ALEA_ipLOADout : STD_LOGIC := '0';
	signal ALEA_ipDINout : STD_LOGIC_VECTOR (15 downto 0):= (others => '0');
	signal ALEA_lidiNOPout : STD_LOGIC:= '0';
	
	--Intermediaire
	--LI/DI
	signal LIDI_NOP : std_logic := '0';
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
	signal MUXREGS_Ain : std_logic_vector(15 downto 0) := (others => '0');
	signal MUXREGS_Aout : std_logic_vector(15 downto 0) := (others => '0');
   signal MUXREGS_DataOUT : std_logic_vector(15 downto 0) := (others => '0');
	
	--DI/EX
	signal DIEX_NOP : std_logic:= '0';
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
	signal LCUAL_out : std_logic_vector(2 downto 0);
	
	-- multiplexeur ual
	signal MUXUAL_OP : std_logic_vector(7 downto 0) := (others => '0');
   signal MUXUAL_B : std_logic_vector(15 downto 0) := (others => '0');
   signal MUXUAL_S : std_logic_vector(15 downto 0) := (others => '0');
	signal MUXUAL_N : std_logic :='0';
	signal MUXUAL_Z : std_logic :='0';
   signal MUXUAL_DataOUT : std_logic_vector(15 downto 0) := (others => '0');
	
	--EX/Mem
	signal EXMEM_NOP : std_logic:= '0';
	signal EXMEM_Ain : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Aout : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_OPin : std_logic_vector(7 downto 0) := (others => '0');
	signal EXMEM_OPout : std_logic_vector(7 downto 0) := (others => '0');
	signal EXMEM_Bin : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Bout : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Cin : std_logic_vector(15 downto 0) := (others => '0');
	signal EXMEM_Cout : std_logic_vector(15 downto 0) := (others => '0');
	
	-- lc memoire données
	signal LCMEM_in : std_logic_vector(7 downto 0) := (others => '0');
	signal LCMEM_out : std_logic := '0';
	
	-- RAM 16 bits 
	signal RAM16_di : std_logic_vector(15 downto 0):= (others => '0');
	signal RAM16_we : std_logic := '0';
	signal RAM16_a : std_logic_vector(15 downto 0):= (others => '0');
	signal RAM16_do : std_logic_vector(15 downto 0):= (others => '0');
	
	-- VGA
	signal VGA_vga_clk : std_logic := '0';
	signal VGA_vga_rst : std_logic := '0';
--	signal VGA_vga_red : std_logic_vector(2 downto 0):= (others => '0');
--	signal VGA_vga_grn : std_logic_vector(2 downto 0):= (others => '0');
--	signal VGA_vga_blu : std_logic_vector(1 downto 0):= (others => '0');
--	signal VGA_vga_hsync : std_logic:= '0';
--	signal VGA_vga_vsync : std_logic:= '0';
	  -- Data bus
	signal VGA_mem_dr : std_logic_vector(15 downto 0):= (others => '0');
	signal VGA_mem_we : std_logic:= '0';
	signal VGA_mem_a : std_logic_vector(10 downto 0):= (others => '0');
	signal VGA_mem_dw : std_logic_vector(15 downto 0):= (others => '0');
	
	--Mem/RE
	signal MEMRE_NOP : std_logic:= '0';
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
	
	-- mux data
	signal MUXDATA_OP :  STD_LOGIC_VECTOR (7 downto 0) := (others => '0');
   signal MUXDATA_B : STD_LOGIC_VECTOR (15 downto 0) := (others => '0');
   signal MUXDATA_DATA_DI : STD_LOGIC_VECTOR (15 downto 0) := (others => '0');
   signal MUXDATA_DataOUT : STD_LOGIC_VECTOR (15 downto 0) := (others => '0');
	
   -- Clock period definitions
	signal CLK_2 : std_logic := '0';
	signal CLK_4 : std_logic := '0';
   constant CLK_period : time := 10 ns;
 
BEGIN
	-- div frequence
	divfreq: div PORT MAP(
		  CLK => CLK,
		  RST => RST,
		  CLK_2 => CLK_2,
		  CLK_4 => CLK_4
	);

	-- ip
	fpga_ip: ip PORT MAP (
		 DIN => IP_DIN,
		 DOUT => IP_DOUT,
		 CLK => CLK,
		 RST => RST,
		 LOAD => IP_LOAD,
		 EN => IP_EN
	  );
	
	-- ip to ram32, prochain instruction
	RAM32_a <= IP_DOUT (13 downto 0) & "00"; --*4
	RAM32_we <= '0';
	
	--ram 32 bits: instructions
	ram32: bram32 PORT MAP (
		  -- System
		  sys_clk => CLK,
		  sys_rst => RST,
		  -- Master
		  di => RAM32_di,
		  we => RAM32_we,
		  a => RAM32_a,
		  do => RAM32_do
	 );
	
	-- ram32 to decode
	DataIN <= RAM32_di;
	
	-- decode unit
	de: decode PORT MAP (
		 DataIN => DataIN,
		 OP => LIDI_OPin,
		 A => LIDI_Ain,
		 B => LIDI_Bin,
		 C => LIDI_Cin
	  );
	
	-- into alea
	ALEA_lidiOPin <= LIDI_OPin;
	ALEA_lidiBin <= LIDI_Bin;
	ALEA_lidiCin <= LIDI_Cin;
	ALEA_diexOPin <= DIEX_OPin;
	ALEA_diexAin <= DIEX_Ain;
	ALEA_diexBin <= DIEX_Bin;
	ALEA_exmemOPin <= EXMEM_OPin;
	ALEA_exmemAin <= EXMEM_Ain;
	ALEA_memreOPin <= MEMRE_OPin;
	ALEA_memreAin <= MEMRE_Ain;
	
	--controleur alea de donnee
    alea : ctlalea PORT MAP( 
		CLK => CLK,
		lidiOPin => ALEA_lidiOPin,
		lidiBin => ALEA_lidiBin,
		lidiCin => ALEA_lidiCin,
		diexOPin => ALEA_diexOPin,
		diexAin => ALEA_diexAin,
		diexBin => ALEA_diexBin,
		exmemOPin => ALEA_exmemOPin,
		exmemAin => ALEA_exmemAin,
		memreOPin => ALEA_memreOPin,
		memreAin => ALEA_memreAin,
		ipENout => ALEA_ipENout,
		ipLOADout => ALEA_ipLOADout,
		ipDINout => ALEA_ipDINout,
		lidiNOPout => ALEA_lidiNOPout
	);
	
	-- out alea
	IP_EN <= ALEA_ipENout;
	IP_LOAD <= ALEA_ipLOADout;
	IP_DIN <= ALEA_ipDINout;
	
	-- out alea
	LIDI_NOP <= ALEA_lidiNOPout;

	-- pipeline li/di
   lidi: pipeline PORT MAP (
          CLK => CLK,
			 NOP => LIDI_NOP,
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
	MUXREGS_Ain <= LIDI_Aout;
	
	-- mux
	muxr: muxregs PORT MAP (
		OP => MUXREGS_OP,
		B => MUXREGS_B,
		QA => MUXREGS_QA,
		Ain => MUXREGS_Ain,
		Aout => MUXREGS_Aout,
		DataOUT => MUXREGS_DataOUT
	);
	
	-- di
	DIEX_OPin <= LIDI_OPout;
	DIEX_Ain <= MUXREGS_Aout;
	DIEX_Bin <= MUXREGS_DataOUT;
	DIEX_Cin <= REG_QB;
	
	-- pipeline di/ex
	diex: pipeline PORT MAP (
          CLK => CLK,
			 NOP => DIEX_NOP,
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
	MUXUAL_N <= UAL_N;
	MUXUAL_Z <= UAL_Z;
	
	-- muxual
	muxu: muxual PORT MAP (
		OP => MUXUAL_OP,
		B => MUXUAL_B,
		S => MUXUAL_S,
		N => MUXUAL_N,
		Z => MUXUAL_Z,
		DataOUT => MUXUAL_DataOUT
	);
	
	-- to exmem
	EXMEM_Bin <= MUXUAL_DataOUT;
	EXMEM_Cin <= x"0000";
	
	-- pipeline ex/mem
	exmem: pipeline PORT MAP (
          CLK => CLK,
			 NOP => EXMEM_NOP,
          OPIN => EXMEM_OPin,
          AIN => EXMEM_Ain,
          BIN => EXMEM_Bin,
          CIN => EXMEM_Cin,
          OPOUT => EXMEM_OPout,
          AOUT => EXMEM_Aout,
          BOUT => EXMEM_Bout,
          COUT => EXMEM_Cout
   );
	
	-- to lc memoire des donnees
	LCMEM_in <= EXMEM_OPout;
	
	-- lc memoire des donnees
	lcm: lcmem PORT MAP(
         OP => LCMEM_in, 
         LC_OUT => LCMEM_out
   );
	
	--lc to ram
	RAM16_we <= LCMEM_out;
	
	--ex/mem to ram
	RAM16_do <= EXMEM_Aout;
	RAM16_a <= EXMEM_Bout (14 downto 0) & "0";--*2
	
	--ram 16 bits
	ram16: bram16 PORT MAP (
		  -- System
		  sys_clk => CLK,
		  sys_rst => RST,
		  -- Master
		  di => RAM16_di,
		  we => RAM16_we,
		  a => RAM16_a,
		  do => RAM16_do
	 );
	 
	-- input VGA//idem ram
	VGA_mem_dw <= EXMEM_Aout;
	VGA_mem_a <= EXMEM_Bout (9 downto 0) & "0";--*2
	VGA_mem_we <= LCMEM_out;
	 
	VGA_vga_clk <= CLK_4;
	VGA_vga_rst <= not(RST);--VGA_vga_rst,sys_reset
	
	-- VGA
	vga: vga_top PORT MAP(
	  -- System
	  sys_clk => CLK,
	  sys_rst => VGA_vga_rst,
	  -- VGA
	  vga_clk => VGA_vga_clk,
	  vga_rst => VGA_vga_rst, 
	  vga_red => VGA_vga_red,
	  vga_grn => VGA_vga_grn,
	  vga_blu => VGA_vga_blu,
	  vga_hsync => VGA_vga_hsync,
	  vga_vsync => VGA_vga_vsync,
	  -- Data bus
	  mem_dr => VGA_mem_dr,
	  mem_we => VGA_mem_we,
	  mem_a => VGA_mem_a,
	  mem_dw => VGA_mem_dw
	);
	
	-- mem
	MEMRE_OPin <= EXMEM_OPout;
	MEMRE_Ain <= EXMEM_Aout;
	MEMRE_Bin <= EXMEM_Bout;
	MEMRE_Cin <= x"0000";
	
	-- pipeline mem/re
	memre: pipeline PORT MAP (
          CLK => CLK,
			 NOP => MEMRE_NOP,
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
	
	--mem/re to mux data
	MUXDATA_B <= MEMRE_Bout;
	MUXDATA_OP <= MEMRE_OPout;
	
	--ram to mux data
	MUXDATA_DATA_DI <= RAM16_di;
	
	 -- Component multiplexeur data
	 muxd: muxdata Port MAP( 
			OP => MUXDATA_OP,
         B => MUXDATA_B, 
         DATA_DI => MUXDATA_DATA_DI,
         DataOUT => MUXDATA_DataOUT 
   );
	
	-- mux data to regs
	REG_Data <= MUXDATA_DataOUT;
	
	-- OUT
	DataOUT <= REG_QB;

end Behavioral;


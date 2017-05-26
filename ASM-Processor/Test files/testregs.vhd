--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:39:36 04/18/2017
-- Design Name:   
-- Module Name:   /home/ymao/Bureau/uProcesseur/testregs.vhd
-- Project Name:  uProcesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: regs
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
 
ENTITY testregs IS
END testregs;
 
ARCHITECTURE behavior OF testregs IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT regs
    PORT(
         adrA : IN  std_logic_vector(3 downto 0);
         adrB : IN  std_logic_vector(3 downto 0);
         adrW : IN  std_logic_vector(3 downto 0);
         W : IN  std_logic;
         Data : IN  std_logic_vector(7 downto 0);
         RST : IN  std_logic;
         CLK : IN  std_logic;
         QA : OUT  std_logic_vector(7 downto 0);
         QB : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal adrA : std_logic_vector(3 downto 0) := (others => '0');
   signal adrB : std_logic_vector(3 downto 0) := (others => '0');
   signal adrW : std_logic_vector(3 downto 0) := (others => '0');
   signal W : std_logic := '0';
   signal Data : std_logic_vector(7 downto 0) := (others => '0');
   signal RST : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal QA : std_logic_vector(7 downto 0);
   signal QB : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: regs PORT MAP (
          adrA => adrA,
          adrB => adrB,
          adrW => adrW,
          W => W,
          Data => Data,
          RST => RST,
          CLK => CLK,
          QA => QA,
          QB => QB
        );

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
		RST <= '0';
		wait for CLK_period*5;
		
		RST <= '1';
		adrW <= "0001";
		Data <= x"AF";
		W <= '1';
		wait for CLK_period*1;
		adrW <= "1111";
		Data <= x"CC";
		wait for CLK_period*1;
		adrW <= "1110";
		Data <= x"BB";
		wait for CLK_period*1;
		adrW <= "1101";
		Data <= x"AA";
		wait for CLK_period*1;
		
		W <= '0';
		adrA <= "0001";
		wait for CLK_period*5;
		
		adrW <= "0011";
		Data <= x"33";
		W <= '1';
		adrB <= "0011";
		wait for CLK_period*5;
		
		RST <= '0';
		wait for CLK_period*5;

      wait;
   end process;

END;

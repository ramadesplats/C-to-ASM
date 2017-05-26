--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:00:49 04/27/2017
-- Design Name:   
-- Module Name:   /home/ymao/Bureau/uProcesseur/testip.vhd
-- Project Name:  uProcesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ip
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
 
ENTITY testip IS
END testip;
 
ARCHITECTURE behavior OF testip IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
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
    

   --Inputs
   signal DIN : std_logic_vector(15 downto 0) := (others => '0');
   signal CLK : std_logic := '0';
   signal RST : std_logic := '0';
   signal LOAD : std_logic := '0';
   signal EN : std_logic := '0';

 	--Outputs
   signal DOUT : std_logic_vector(15 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ip PORT MAP (
          DIN => DIN,
          DOUT => DOUT,
          CLK => CLK,
          RST => RST,
          LOAD => LOAD,
          EN => EN
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
		
		RST <= '1';
		
      wait;
   end process;

END;

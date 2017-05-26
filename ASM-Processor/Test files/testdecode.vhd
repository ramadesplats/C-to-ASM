--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:13:13 04/27/2017
-- Design Name:   
-- Module Name:   /home/ymao/Bureau/uProcesseur/testdecode.vhd
-- Project Name:  uProcesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: decode
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
 
ENTITY testdecode IS
END testdecode;
 
ARCHITECTURE behavior OF testdecode IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT decode
    PORT(
         DataIN : IN  std_logic_vector(31 downto 0);
         OP : OUT  std_logic_vector(7 downto 0);
         A : OUT  std_logic_vector(15 downto 0);
         B : OUT  std_logic_vector(15 downto 0);
         C : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal DataIN : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal OP : std_logic_vector(7 downto 0);
   signal A : std_logic_vector(15 downto 0);
   signal B : std_logic_vector(15 downto 0);
   signal C : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   --constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: decode PORT MAP (
          DataIN => DataIN,
          OP => OP,
          A => A,
          B => B,
          C => C
        );

   -- Clock process definitions
--   <clock>_process :process
--   begin
--		<clock> <= '0';
--		wait for <clock>_period/2;
--		<clock> <= '1';
--		wait for <clock>_period/2;
--   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

--      wait for <clock>_period*10;

      -- insert stimulus here 
		
		DataIN <= x"0501ABCD";
		wait for 100 ns;	
		
		DataIN <= x"0601ABCD";
		wait for 100 ns;	
		
		DataIN <= x"0E01ABCD";
		wait for 100 ns;	
		
		DataIN <= x"0F01ABCD";
		wait for 100 ns;	
		
		DataIN <= x"1001ABCD";
		wait for 100 ns;	
		
		DataIN <= x"0301ABCD";
		wait for 100 ns;	
		

      wait;
   end process;

END;

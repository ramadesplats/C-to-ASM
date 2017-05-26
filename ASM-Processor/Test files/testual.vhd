--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:21:12 03/31/2017
-- Design Name:   
-- Module Name:   /home/ymao/Bureau/uProcesseur/testual.vhd
-- Project Name:  uProcesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ual
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
USE ieee.numeric_std.ALL;
 
ENTITY testual IS
END testual;
 
ARCHITECTURE behavior OF testual IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
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
	 
	 component bram32
	 generic (
		init_file : String := "none";
		--valeur par défaut, initialisation de mémoire.
		--mettre instructions quand instruction (type 0601ABCD)
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
    

   --Inputs
   signal A : std_logic_vector(15 downto 0) := (others => '0');
   signal B : std_logic_vector(15 downto 0) := (others => '0');
   signal Ctrl_Alu : std_logic_vector(2 downto 0) := (others => '0');
	signal CLK : std_logic;

 	--Outputs
   signal N : std_logic;
   signal O : std_logic;
   signal Z : std_logic;
   signal C : std_logic;
   signal S : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the BRAM 32
	--memoire_de_programe : bram32 port map (
		--Faire la connexion des signaux
	--);
	
	-- Instantiate the Unit Under Test (UUT)
   uut: ual PORT MAP (
          A => A,
          B => B,
          Ctrl_Alu => Ctrl_Alu,
          N => N,
          O => O,
          Z => Z,
          C => C,
          S => S
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
		
		A <= std_logic_vector(to_unsigned(5, 16));
		B <= std_logic_vector(to_unsigned(10, 16));
		Ctrl_Alu <= "001";
		wait for CLK_period*5; -- add
		
		Ctrl_Alu <= "011";
		wait for CLK_period*5; -- mul
		
		Ctrl_Alu <= "010";
		wait for CLK_period*5; -- sub, Negativ
		
		A <= x"FFFF";
		B <= x"0001";
		Ctrl_Alu <= "001";
		wait for CLK_period*5; --add, Carry, Zero
		
		A <= x"7ABC";
		B <= x"3111";
		wait for CLK_period*5; --add, Overflow
		
		A <= x"0005";
		B <= x"0010";
		Ctrl_Alu <= "010";
		wait for CLK_period*5; --sub
		
		A <= x"2452";
		B <= x"F637";
		Ctrl_Alu <= "011";
		wait for CLK_period*5; --mul, Overflow

      wait;
   end process;

END;

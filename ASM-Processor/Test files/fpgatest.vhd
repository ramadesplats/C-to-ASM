--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:58:08 05/02/2017
-- Design Name:   
-- Module Name:   /home/ymao/Bureau/uProcesseur/fpgatest.vhd
-- Project Name:  uProcesseur
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: fpga
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
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY fpgatest IS
END fpgatest;
 
ARCHITECTURE behavior OF fpgatest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT fpga
    PORT(
			RST : in STD_LOGIC;
         CLK : IN  std_logic;
         DataOUT : OUT  std_logic_vector(15 downto 0);
			--VGA_vga_clk : in std_logic ;
			--VGA_vga_rst : in std_logic;
			VGA_vga_red : out std_logic_vector(2 downto 0);
			VGA_vga_grn : out std_logic_vector(2 downto 0);
			VGA_vga_blu : out std_logic_vector(1 downto 0);
			VGA_vga_hsync : out std_logic;
			VGA_vga_vsync : out std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
	signal RST : std_logic := '0';

 	--Outputs
   signal DataOUT : std_logic_vector(15 downto 0);
	
	signal VGA_vga_red : std_logic_vector(2 downto 0);
	signal VGA_vga_grn : std_logic_vector(2 downto 0);
	signal VGA_vga_blu : std_logic_vector(1 downto 0);
	signal VGA_vga_hsync : std_logic;
	signal VGA_vga_vsync : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: fpga PORT MAP (
			 RST => RST,
          CLK => CLK,
          DataOUT => DataOUT,
			 VGA_vga_red => VGA_vga_red,
			 VGA_vga_grn => VGA_vga_grn,
			 VGA_vga_blu => VGA_vga_blu,
			 VGA_vga_hsync => VGA_vga_hsync,
			 VGA_vga_vsync => VGA_vga_vsync
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
      wait for CLK_period*10;
		
		RST <= '1';
		

      wait;
   end process;

END;

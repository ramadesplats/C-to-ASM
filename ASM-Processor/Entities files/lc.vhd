----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:34:35 04/27/2017 
-- Design Name: 
-- Module Name:    lc - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity lc is
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           LC_OUT : out  STD_LOGIC);
end lc;

architecture Behavioral of lc is

begin

logic_controller : process (OP) is
begin
	case OP is
	when x"01" => --ADD
		LC_OUT <= '1';
	when x"02" => --MUL
		LC_OUT <= '1';
	when x"03" => --SUB
		LC_OUT <= '1';
	when x"04" => --DIV
		LC_OUT <= '1';
	when x"05" => --COP
		LC_OUT <= '1';
	when x"06" => --AFC
		LC_OUT <= '1';
	when x"07" => --LOAD
		LC_OUT <= '1';
	when x"09" => --EQU
		LC_OUT <= '1';
	when x"0A" => --INF
		LC_OUT <= '1';
	when x"0B" => --INFE
		LC_OUT <= '1';
	when x"0C" => --SUP
		LC_OUT <= '1';
	when x"0D" => --SUPE
		LC_OUT <= '1';
	when others => 
		LC_OUT <= '0';
	end case;
end process;

end Behavioral;


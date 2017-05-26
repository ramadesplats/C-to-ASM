----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:48:43 05/02/2017 
-- Design Name: 
-- Module Name:    lcual - Behavioral 
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

entity lcual is
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           LC_OUT : out  STD_LOGIC_VECTOR (2 downto 0));
end lcual;

architecture Behavioral of lcual is

begin

logic_controller : process (OP) is
begin
	case OP is
	when x"01" => --ADD
		LC_OUT <= "001";
	when x"02" => --MUL
		LC_OUT <= "010";
	when x"03"	=> --SUB
		LC_OUT <= "011";
	when x"04" => --DIV -- pas encore implemente dans ual
		LC_OUT <= "100";
	when x"07" => --LOAD, offset+R31
		LC_OUT <= "001";
	when x"08" => --STORE, offset+R31
		LC_OUT <= "001";
	when others => 
		LC_OUT <= "000";
	end case;
end process;

end Behavioral;


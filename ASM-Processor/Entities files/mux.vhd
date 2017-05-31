----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:08:53 05/02/2017 
-- Design Name: 
-- Module Name:    mux - Behavioral 
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

entity muxregs is
    Port ( OP : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           QA : in  STD_LOGIC_VECTOR (15 downto 0);
			  Ain: in  STD_LOGIC_VECTOR (15 downto 0);
			  Aout: out  STD_LOGIC_VECTOR (15 downto 0);
           DataOUT : out  STD_LOGIC_VECTOR (15 downto 0));
end muxregs;

architecture Behavioral of muxregs is

begin

multiplexeur : process (OP, B, QA, Ain) is
begin
	case OP is
	when x"01" => --ADD
		Aout <= Ain;
		DataOUT <= QA;
	when x"02" => --MUL
		Aout <= Ain;
		DataOUT <= QA;
	when x"03" => --SUB
		Aout <= Ain;
		DataOUT <= QA;
	when x"04" => --DIV
		Aout <= Ain;
		DataOUT <= QA;
	when x"05" => --COP
		Aout <= Ain;
		DataOUT <= QA;
	when x"08" => --STORE
		-- on passe Ain=offset, QA=Ri, on permute QA et A
		Aout <= QA;
		DataOUT <= Ain;
	when x"09" => --EQU
		Aout <= Ain;
		DataOUT <= QA;
	when x"0A" => --INF
		Aout <= Ain;
		DataOUT <= QA;
	when x"0B" => --INFE
		Aout <= Ain;
		DataOUT <= QA;
	when x"0C" => --SUP
		Aout <= Ain;
		DataOUT <= QA;
	when x"0D" => --SUPE
		Aout <= Ain;
		DataOUT <= QA;
	when x"0F" => --JUMPC
		Aout <= Ain;
		DataOUT <= QA;
	when x"10" => --JUMPR
		-- on passe Ain=QA(Ri), on n'a pas besoin de B donc on le laisse tel quel
		Aout <= QA;
		DataOUT <= Ain;
	when others => 
		Aout <= Ain;
		DataOUT <= B;
	end case;
end process;

end Behavioral;


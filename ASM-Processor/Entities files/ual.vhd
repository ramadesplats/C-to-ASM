----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:07:52 03/31/2017 
-- Design Name: 
-- Module Name:    ual - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ual is
    Port ( A : in  STD_LOGIC_VECTOR (15 downto 0);
           B : in  STD_LOGIC_VECTOR (15 downto 0);
           Ctrl_Alu : in  STD_LOGIC_VECTOR (2 downto 0);
           N : out  STD_LOGIC;
           O : out  STD_LOGIC;
           Z : out  STD_LOGIC;
           C : out  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (15 downto 0));
end ual;

architecture Behavioral of ual is
	signal result : STD_LOGIC_VECTOR(31 downto 0);
	constant zero16b : STD_LOGIC_VECTOR(16 downto 0) := (others=>'0');
	constant max16b : STD_LOGIC_VECTOR(16 downto 0) := (15 downto 0 => '1', others=> '0');
begin

calcul : process (A, B, Ctrl_Alu) is
begin
	case Ctrl_Alu is
	when "001" => -- add 1
		result <= (x"0000" & A) + (x"0000" & B);
	when "010" => --mul 2
		result <= A * B;
	when "011" => --sub 3
		result <= (x"0000" & A) -(x"0000" & B);
	when others => --000
		--result <= (others=>'0');
	end case;
end process;

S <= result(15 downto 0);

flagZ : process (result) is
begin
	if result(15 downto 0) = x"0000" then
		Z <= '1';
	else
		Z <= '0';
	end if;
end process;

-- Negatif, utile uniquement si Overflow = '0'
N <= result(15);

C <= result(16);

flagO : process (result, A, B, Ctrl_Alu) is
begin
	case Ctrl_Alu is
	when "001" => -- add
		O <= (A(15) and B(15) and not(result(15))) or  (not(A(15)) and not(B(15)) and result(15));
	when "010" => --sub
		O <= (A(15) and not(result(15))) or (not(A(15)) and result(15));
	when "011" => --mul
		O <= result(31) or result(30) or  result(29) or result(28) or result(27) or result(26) or result(25) or result(24) or result(23)
 or result(22) or result(21) or result(20) or result(19) or result(18) or result(17) or result(16);
	when others => --000
		O <= '0';
	end case;
end process;


end Behavioral;


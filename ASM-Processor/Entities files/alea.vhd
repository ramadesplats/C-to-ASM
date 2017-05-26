----------------------------------------------------------------------------------
-- Company:
-- Engineer:
--
-- Create Date:    11:13:34 04/27/2017
-- Design Name:
-- Module Name:    Gestion_Aleas - Behavioral
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
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Gestion_Aleas is
   Port ( OP1 : in  STD_LOGIC_VECTOR (7 downto 0);
          RA1 : in  STD_LOGIC_VECTOR (15 downto 0);
          RB1 : in  STD_LOGIC_VECTOR (15 downto 0);
          RC1 : in  STD_LOGIC_VECTOR (15 downto 0);
			 OP2 : in  STD_LOGIC_VECTOR (7 downto 0);
          RA2 : in  STD_LOGIC_VECTOR (15 downto 0);
          RB2 : in  STD_LOGIC_VECTOR (15 downto 0);
          RC2 : in  STD_LOGIC_VECTOR (15 downto 0);
			 OP3 : in  STD_LOGIC_VECTOR (7 downto 0);
          RA3 : in  STD_LOGIC_VECTOR (15 downto 0);
          RB3 : in  STD_LOGIC_VECTOR (15 downto 0);
          RC3 : in  STD_LOGIC_VECTOR (15 downto 0);
			 OP4 : in  STD_LOGIC_VECTOR (7 downto 0);
          RA4 : in  STD_LOGIC_VECTOR (15 downto 0);
          RB4 : in  STD_LOGIC_VECTOR (15 downto 0);
			 OP5 : in  STD_LOGIC_VECTOR (7 downto 0);
          RA5 : in  STD_LOGIC_VECTOR (15 downto 0);
          RB5 : in  STD_LOGIC_VECTOR (15 downto 0);
          OP_out : out  STD_LOGIC_VECTOR (7 downto 0);
			 EN_out : out  STD_LOGIC
		   );
end Gestion_Aleas;

architecture Behavioral of Gestion_Aleas is
	signal int_op : STD_LOGIC_VECTOR (7 downto 0);
	
begin
	int_op <= x"00" when( 	(	( (OP1 = 1) or (OP1 = 2) or (OP1 = 3) or (OP1 = 4) )
								and ( 	(( (RB1 = RA2) or (RC1 = RA2) ) and ( (OP2 = 5) or (OP2 = 6) or (OP2 = 7) ))
										or	(( (RB1 = RA3) or (RC1 = RA3) ) and ( (OP3 = 5) or (OP3 = 6) or (OP3 = 7) ))
										or	(( (RB1 = RA4) or (RC1 = RA4) ) and ( (OP4 = 5) or (OP4 = 6) or (OP4 = 7) ))
										or	(( (RB1 = RA5) or (RC1 = RA5) ) and ( (OP5 = 5) or (OP5 = 6) or (OP5 = 7) ))
									)
								)
							or	(	( (OP1 = 8) or (OP1 = 15) )
								and ( 	(( (RB1 = RA2) ) and ( (OP2 = 5) or (OP2 = 6) or (OP2 = 7) ))
									or	(( (RB1 = RA3) ) and ( (OP3 = 5) or (OP3 = 6) or (OP3 = 7) ))
									or	(( (RB1 = RA4) ) and ( (OP4 = 5) or (OP4 = 6) or (OP4 = 7) ))
									or	(( (RB1 = RA5) ) and ( (OP5 = 5) or (OP5 = 6) or (OP5 = 7) ))
									)
								)
							or ( (OP1 = 16)
								and ( 	(( (RA1 = RA2) ) and ( (OP2 = 5) or (OP2 = 6) or (OP2 = 7) ))
									or	(( (RA1 = RA3) ) and ( (OP3 = 5) or (OP3 = 6) or (OP3 = 7) ))
									or	(( (RA1 = RA4) ) and ( (OP4 = 5) or (OP4 = 6) or (OP4 = 7) ))
									or	(( (RB1 = RA5) ) and ( (OP5 = 5) or (OP5 = 6) or (OP5 = 7) ))
									
									)
								)
							or (	( 		( (OP1 = 1) or (OP1 = 2) or (OP1 = 3) or (OP1 = 4) )
									and ( 			( (OP2 = 1) or (OP2 = 2) or (OP2 = 3) or (OP2 = 4) )
												or	( (OP3 = 1) or (OP3 = 2) or (OP3 = 3) or (OP3 = 4) )
												or	( (OP4 = 1) or (OP4 = 2) or (OP4 = 3) or (OP4 = 4) )
												or	( (OP5 = 1) or (OP5 = 2) or (OP5 = 3) or (OP5 = 4) )
										)
								)
								and (		( (RB1 = RA2) or (RC1 = RA2) )
										or	( (RB1 = RA3) or (RC1 = RA3) )
										or	( (RB1 = RA4) or (RC1 = RA4) )
										or	( (RB1 = RA4) or (RC1 = RA5) )
									)						
							)
							--aléa de branchement
							or	(		(OP2 = 14) or (OP2 = 15) or (OP2 = 16) or (OP3 = 14) or (OP3 = 15) or (OP3 = 16)
									or (OP4 = 14) or (OP4 = 15) or (OP4 = 16)	or (OP5 = 14) or (OP5 = 15) or (OP5 = 16)
								)
							)

					else OP1;
						
	OP_out <= int_op;
	EN_out <= '0' when (int_op = 0) else '1';
						
						

end Behavioral;

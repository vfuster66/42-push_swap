# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfuster- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 08:04:07 by vfuster-          #+#    #+#              #
#    Updated: 2023/06/30 15:39:47 by vfuster-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIRE=0;
MEILLEUR=0;
MOYENNE=0;
NBR=0;

#modification ici :#
MINI=-100000;
MAXI=100000;
NBR_OF_NBRS=500;
NBR_OF_TESTS=100;
NBR_OF_TESTS_ABS=100;

while [ $NBR_OF_TESTS -gt 0 ]
do
	echo $NBR_OF_TESTS;
   NBR=$(ARG=$(seq $(( $MINI )) $MAXI | shuf -n $NBR_OF_NBRS | xargs); ./push_swap $ARG | wc -l);
   MOYENNE=$(( MOYENNE + NBR ));
   NBR_OF_TESTS=$((NBR_OF_TESTS-1));
   if [ $(( NBR_OF_TESTS_ABS - NBR_OF_TESTS )) -eq 1 ]
   then
      PIRE=$NBR;
      MEILLEUR=$NBR;
   else
      if [ $NBR -gt $PIRE ]
      then
         PIRE=$NBR;
      fi
      if [ $MEILLEUR -gt $NBR ]
      then
         MEILLEUR=$NBR;
      fi
   fi
done
MOYENNE=$(( MOYENNE / NBR_OF_TESTS_ABS));

echo "J'ai fait $NBR_OF_TESTS_ABS tests avec $NBR_OF_NBRS nombres compris entre $MINI et $MAXI.";
echo "Votre pire score est $PIRE";
echo "Votre meilleur score est $MEILLEUR";
echo "Votre moyenne est $MOYENNE";

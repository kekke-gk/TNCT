/***  p02ex09.c  ***/
/***  s12083  2J18  �ܖ����S  ***/

#include <stdio.h>

int main()
{
	int n,m,i,j,k,l;
	scanf("%d",&n);
	m=n-n/2;
	
	for(i=0;i<m;i++){
		for(j=0;j<m-i-1;j++){
			printf("-");
		}
		for(k=0;k<n-j*2;k++){
			printf("*");
		}
		for(l=0;l<j;l++){
			printf("-");
		}
		printf("\n");
		j=0;
	}

	return 0;
}

/*
	int n,m,i,j;
	scanf("%d",&n);
	m=n-n/2;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(j<m-i-1 || j>m+i-1){
				printf("-");
			}else printf("*");
		}
		printf("\n");
	}

	return 0;
}
*/

/**************** ���s���� *****************
1
*

3
-*-
***

5
--*--
-***-
*****

7
---*---
--***--
-*****-
*******

9
----*----
---***---
--*****--
-*******-
*********

79
---------------------------------------*---------------------------------------
--------------------------------------***--------------------------------------
-------------------------------------*****-------------------------------------
------------------------------------*******------------------------------------
-----------------------------------*********-----------------------------------
----------------------------------***********----------------------------------
---------------------------------*************---------------------------------
--------------------------------***************--------------------------------
-------------------------------*****************-------------------------------
------------------------------*******************------------------------------
-----------------------------*********************-----------------------------
----------------------------***********************----------------------------
---------------------------*************************---------------------------
--------------------------***************************--------------------------
-------------------------*****************************-------------------------
------------------------*******************************------------------------
-----------------------*********************************-----------------------
----------------------***********************************----------------------
---------------------*************************************---------------------
--------------------***************************************--------------------
-------------------*****************************************-------------------
------------------*******************************************------------------
-----------------*********************************************-----------------
----------------***********************************************----------------
---------------*************************************************---------------
--------------***************************************************--------------
-------------*****************************************************-------------
------------*******************************************************------------
-----------*********************************************************-----------
----------***********************************************************----------
---------*************************************************************---------
--------***************************************************************--------
-------*****************************************************************-------
------*******************************************************************------
-----*********************************************************************-----
----***********************************************************************----
---*************************************************************************---
--***************************************************************************--
-*****************************************************************************-
*******************************************************************************

*******************************************/
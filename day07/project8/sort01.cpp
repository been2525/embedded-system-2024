#include <stdio.h>

void array(int ary[])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int num = ary[j];
			if (ary[i] < ary[j])
			{
				ary[j] = ary[i];
				ary[i] = num;
			}

		}
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", ary[i]);
	}
}

void main()
{
	int ary[] = { 9,4,8,15,3,7,2,1 };		//오름차순으로 정렬해보시오
	array(ary);
	/*
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int num = ary[j];
			if (ary[i] < ary[j])
			{
				ary[j] = ary[i];
				ary[i] = num;
			}

		}
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%d\n", ary[i]);
	}
	*/
	/*
	int size = sizeof(ary) / sizeof(ary[0]); //(8*4)/(1*4) = 8 //강사님이 하신것
	for(int i =0; i<size -1; i++)
	{
		for(int j = 0; j<size - 1; j++)
		{
			if(ary[j]>ary[j+1])
			{
				temp = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = temp;
			}
		}
	}*/
}
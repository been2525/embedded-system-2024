/*ÀÌÁøÅ½»ö*/
#include <stdio.h>

void vsearch(int _ary[], int _size, int _num);

void main()
{
   int ary[] = { 1, 2, 3, 4, 5, 8, 9 };
   int size = sizeof(ary) / sizeof(ary[0]);
   int first = 0;
   int last = size;
   int middle = 0;
   vsearch(ary, size, 8);
   return;
/*
    while(first <=  last)
    {
	    middle = (first + last) / 2;
		if(target == ary[middle])
	    {
			printf("%d\n", ary[middle]);
		}
		else
		{
	        if (target > ary[middle])
	        {
		        first = middle + 1;
			}
			else last = middle - 1;
		}
 }*/
}

void vsearch(int _ary[], int _size, int _num)
{
   int first = 0;
   int last = _size - 1;
   int target = _num;
   while (first <= last)
   {
	   int middle = (first + last) / 2;
	   if (target == _ary[middle])
	   {
			printf("%d\n", _ary[middle]);
		}
		else
	   {
		     if (target > _ary[middle])
		     {
			     first = middle + 1;
		     }
		      else last = middle - 1;
	   }
   }
}

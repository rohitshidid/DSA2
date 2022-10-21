#include <stdio.h>
#include<stdlib.h>
#include "student_info.h"
#include"file.h"



void main()
{	char file_n[]= "test.bat";
	int choice;
	while(1)
	{
		printf("\n1.Insert.\n2.Search\n3.Delete\n4.Display\n5.Stream Display\n6.Exit\nEnter Choice = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_stud(file_n);
			break;
			
			case 2:
				search(file_n);
			break;
			
			case 3:
				delete_stud(file_n);
			break;
			
			case 4:
				display_file(file_n);
			break;
			
			case 5:
				dept_vise_cnt(file_n);
			break;
			
			case 6:
				return;
				
			break;
			
			default:
				printf("\nPlease Enter from the above choice......");
		}
	}
	
	//
	return;
}

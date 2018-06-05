#include <stdio.h>
#include <stdlib.h>


void decimal_2_binary(int n)
{
    if(n == 0)
        return;

    decimal_2_binary(n/2);

    printf("%d" , n%2);

}






void decimal_2_oct(int n)
{
    if(n == 0)
        return;

    decimal_2_oct(n/8);

    printf("%d" , n%8);

}




struct complex {

float real ;
float imj;

};

void add_complex(struct complex x , struct complex y , struct complex *result)
{


    result->real = x.real + y.real;
    result->imj = x.imj + y.imj;

}



void sub_complex(struct  complex x , struct complex y , struct complex *result)
{


    result->real = x.real - y.real;
    result->imj = x.imj - y.imj;

}




void mul_complex(struct  complex x , struct complex y , struct complex *result)
{

    result->real = x.real * y.real - x.imj * y.imj;
    result->imj = x.real * y.imj + x.imj * y.real;

}



void add_matrix( float A[100][100] , float B[100][100] , float C[100][100] , int n , int m)
{
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
        C[i][j] = A[i][j] + B[i][j];
}



void sub_matrix( float A[100][100] , float B[100][100] , float C[100][100] , int n , int m)
{
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
        C[i][j] = A[i][j] - B[i][j];
}

// n - > A.rows
// m - > A.cols
// p -> B.cols
void mul_matrix( float A[100][100] , float B[100][100] , float C[100][100] , int n , int m , int p)
{

     for(int i = 0 ; i < n ; i++ )
                    for(int j = 0 ; j < p ; j++)
                        C[i][j] = 0;


     for (int i=0;i<n;i++)
        for (int j=0;j<p;j++)
            for (int k=0;k<m;k++)
            C[i][j] += A[i][k]*B[k][j];
}






 // Matrices
    float A [100][100];
    int rowsA;
    int colsA;
    float B [100][100];
    int rowsB;
    int colsB;
    float C [100][100];
    int rowsC;
    int colsC;




int main()
{

    int mode;
    char again;
    char _operator; // operator


    // Normal
    float x ; // first operand
    float y ; // second operand
    float result; // result

    // Complex
    struct complex c1;
    struct complex c2;
    struct complex comp_result;

    // Logic
    int a ; // first logic operand
    int b ; // second logic operand
    int c ; // result binary
    char logic_mode;



    printf("Please select the mode: \n"
           "0 -> normal operations \n"
           "1 -> complex operations \n"
           "2 -> logical operations \n"
           "3 -> matrices operations \n");

     scanf("%d",&mode);


switch (mode)
{



    case 0: // Normal Operations

        do
        {

        printf("enter the first operand then enter operator then enter second operand \n");


            scanf("%f" , &x);
            fflush(stdin);
            scanf("%c" , &_operator);
            fflush(stdin);
            scanf("%f" , &y);
            fflush(stdin);

            switch(_operator)
            {
            case'+':
                result = x + y ;
                printf("%f",result);
                break;

            case'-':
                result = x - y ;
                printf("%f",result);
                break;

            case'*':
                result = x * y ;
                printf("%f",result);
                break;


            case'/':
                result = x / y ;
                printf("%f",result);
                break;


            default:
                result = 0;
                printf("%f" , result);

            }


            printf("\nenter '1' to calculate again any thing else to exit: \n");
            scanf("%c",&again);
            fflush(stdin);

        }
            while(again == '1');

        break;




    case 1: // Complex Operations

        do
        {

        printf("enter the real part of first operand \n");
            scanf("%f" , &c1.real);
            fflush(stdin);


        printf("enter the imaginary part of first operand \n");
            scanf("%f" , &c1.imj);
            fflush(stdin);



        printf("select one of these operators '+' , '-' , '*' \n");
            scanf("%c" , &_operator);
            fflush(stdin);





        printf("enter the real part of second operand \n");
            scanf("%f" , &c2.real);
            fflush(stdin);


        printf("enter the imaginary part of second operand \n");
            scanf("%f" , &c2.imj);
            fflush(stdin);



            switch(_operator)
            {
            case'+':
                add_complex(c1,c2,&comp_result);
                printf("result = real -> %f \t imaginary -> %f ",comp_result.real,comp_result.imj);
                break;

            case'-':
                sub_complex(c1,c2,&comp_result );
                printf("result = real -> %f \t imaginary -> %f ",comp_result.real,comp_result.imj);
                break;

            case'*':
                mul_complex(c1,c2,&comp_result );
                printf("result = real -> %f \t imaginary -> %f ",comp_result.real,comp_result.imj);
                break;



            default:
                comp_result.real = 0 ; comp_result.imj = 0;
                printf("result = real -> %f \t imaginary -> %f ",comp_result.real,comp_result.imj);

            }


            printf("\nenter '1' to calculate again any thing else to exit: \n");
            scanf("%c",&again);
            fflush(stdin);

        }
            while(again == '1');


        break;




case 2: // Logic Operations

        do
        {

        printf("enter the decimal value of first operand \n");
            scanf("%d" , &a);
            fflush(stdin);



        printf("select one of these operators '|' , '&' , '^' , \n");
            scanf("%c" , &_operator);
            fflush(stdin);


        printf("enter the decimal value of second operand \n");
            scanf("%d" , &b);
            fflush(stdin);


        printf("enter the desired format of the output \n"
               "'B' -> binary \n"
               "'X' -> hex \n"
               "'O' -> octal \n"
               "any thing else -> decimal \n");
            scanf("%c" , &logic_mode);
            fflush(stdin);




            switch(_operator)
            {
            case'|':
                c = a | b;
                if(logic_mode == 'B')
                decimal_2_binary(c);

                else if(logic_mode == 'X')
                printf("%x",c);

                else if(logic_mode == 'O')
                decimal_2_oct(c);

                else
                printf("%d",c);
                printf("\n");
                break;

            case'&':
                c = a & b;
                if(logic_mode == 'B')
                decimal_2_binary(c);

                else if(logic_mode == 'X')
                printf("%x",c);

                else if(logic_mode == 'O')
                decimal_2_oct(c);

                else
                printf("%d",c);
                printf("\n");
                break;



         case'^':
                c = a ^ b;
                if(logic_mode == 'B')
                decimal_2_binary(c);

                else if(logic_mode == 'X')
                printf("%x",c);

                else if(logic_mode == 'O')
                decimal_2_oct(c);

                else
                printf("%d",c);
                printf("\n");
                break;



            default:
                c = 0;
                printf("result = %b" , c);

            }


            printf("\nenter '1' to calculate again any thing else to exit: \n");
            scanf("%c",&again);
            fflush(stdin);

        }
            while(again == '1');


        break;






    case 3: // Matrices Operations

        do
        {

        printf("enter the first matrix row numbers \n");

            scanf("%d" , &rowsA);
            fflush(stdin);

        printf("enter the first matrix col numbers \n");

            scanf("%d" , &colsA);
            fflush(stdin);

        printf("enter elements: \n");

        for(int i = 0 ; i < rowsA ; i++)
        {
            for(int j = 0 ; j < colsA ; j++)
            {
                scanf("%f" , &A[i][j]);
                 fflush(stdin);

            }

            printf("--- end of a row ---\n");
        }



        printf("select one of these operators '+' , '-' , '*' \n");
            scanf("%c" , &_operator);
            fflush(stdin);




        printf("enter the second matrix row numbers \n");

            scanf("%d" , &rowsB);
            fflush(stdin);

        printf("enter the second matrix col numbers \n");

            scanf("%d" , &colsB);
            fflush(stdin);

        printf("enter elements: \n");

        for(int i = 0 ; i < rowsB ; i++)
        {
            for(int j = 0 ; j < colsB ; j++)
            {
                scanf("%f" , &B[i][j]);
                 fflush(stdin);
            }

            printf("--- end of a row ---\n");
        }






            switch(_operator)
            {
            case'+':
                add_matrix(A,B,C,rowsA,colsA);

                for(int i = 0 ; i < rowsA ; i++)
                {
                    for(int j = 0 ; j < colsA ; j++)
                    printf("%f \t" , C[i][j]);

                 printf("\n");
                }

                break;


                case'-':
                sub_matrix(A,B,C,rowsA,colsA);

                for(int i = 0 ; i < rowsA ; i++)
                {
                    for(int j = 0 ; j < colsA ; j++)
                    printf("%f \t" , C[i][j]);

                 printf("\n");
                }
                break;



            case'*':
                mul_matrix(A,B,C,rowsA,colsA,colsB);
                    for(int i = 0 ; i < rowsA ; i++)
                {
                    for(int j = 0 ; j < colsB ; j++)
                    printf("%f \t" , C[i][j]);

                 printf("\n");
                }
                break;





            default:
                for(int i = 0 ; i < rowsA ; i++ )
                    for(int j = 0 ; j < colsA ; j++)
                    C[i][j] = 0;

                    for(int i = 0 ; i < rowsA ; i++)
                {
                    for(int j = 0 ; j < colsA ; j++)
                    printf("%f \t" , C[i][j]);

                 printf("\n");
                }

            }

            printf("\nenter '1' to calculate again any thing else to exit: \n");
            scanf("%c",&again);
            fflush(stdin);

        }
            while(again == '1');

        break;





    default:
    printf("error \n");

}
    return 0;
}

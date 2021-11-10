
#include "gtest/gtest.h"

int add(int a,int b)
{
    return a+b;
}

//  Returns true iff n is a prime number.
bool  IsPrime( int n)
{
     //  Trivial case 1: small numbers
     if  (n  <=   1 )  return   false ;

     //  Trivial case 2: even numbers
     if  (n  %   2   ==   0 )  return  n  ==   2 ;

     //  Now, we have that n is odd and n >= 3.

     //  Try to divide n by every odd number i, starting from 3
     for  ( int  i  =   3 ; ; i  +=   2 ) {
         //  We only have to try i up to the squre root of n
         if  (i  >  n / i)  break ;

         //  Now, we have i <= n/i < n.
         //  If n is divisible by i, n is not prime.
         if  (n  %  i  ==   0 )  return   false ;
    }
     //  n has no integer factor in the range (1, n), and thus is prime.
     return   true ;
}

class  IsPrimeParamTest :  public ::testing::TestWithParam < int >
{

};

//使用参数化后的方案
TEST_P(IsPrimeParamTest, HandleTrueReturn)
{
     int  n  =   GetParam();
    EXPECT_TRUE(IsPrime(n));
}

INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Values( 3 ,  5 ,  11 ,  23 ,  17, 23));

//INSTANTIATE_TEST_CASE_P(TrueReturn, IsPrimeParamTest, testing::Range(1, 100, 2));

TEST(testCase,test0)
{
    EXPECT_EQ(add(2,3),5);
}

TEST(testCase,test1)
{
    EXPECT_NE(add(2,3),6);
}

TEST(testCase,test2)
{
    ASSERT_EQ(add(2,3),5);
}

TEST(testCase1,test0)
{
    EXPECT_EQ(add(2,3),5);
}

TEST(testCase1,test1)
{
    EXPECT_NE(add(2,3),6);
}

TEST(testCase1,test2)
{
    ASSERT_EQ(add(2,3),5);
}

extern int addevent(void);

int main(int argc,char **argv)
{
	addevent();
  testing::InitGoogleTest(&argc,argv);

  return RUN_ALL_TESTS();
}



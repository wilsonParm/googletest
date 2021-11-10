
#include "gtest/gtest.h"

//事件机制

//1.全局事件
class  FooEnvironment :  public  testing::Environment
{
public :
     virtual   void  SetUp()
    {
        std::cout  <<   " Foo FooEnvironment SetUP "   <<  std::endl;
    }
     virtual   void  TearDown()
    {
        std::cout  <<   " Foo FooEnvironment TearDown "   <<  std::endl;
    }
};

int  addevent(void)
{
	//
    testing::AddGlobalTestEnvironment( new  FooEnvironment);
	
	return 0;
}

//2.TestSuite事件
class  FooTest :  public  testing::Test {
  protected :
   static   void  SetUpTestCase() {
//    shared_resource_  =   new  ;
	std::cout  <<   " FooTest SetUpTestCase "   <<  std::endl;
  }
   static   void  TearDownTestCase() {
//    delete shared_resource_;
//    shared_resource_  =  NULL;
	std::cout  <<   " FooTest TearDownTestCase "   <<  std::endl;
  }
   //  Some expensive resource shared by all tests.
//   static  T *  shared_resource_;
};

TEST_F(FooTest, Test1)
 {
     //  you can refer to shared_resource here 
}
TEST_F(FooTest, Test2)
 {
     //  you can refer to shared_resource here 
}

//3. TestCase事件
class FooCalc
{
		public:
	static void Init()
	{
			std::cout  <<   "Calc.Init"   <<  std::endl;

	}

static int Calc(int a, int b)
	{
		
		return a>b ? a-b : b-a;
	}
	
	static void Finalize()
	{
			std::cout  <<   "Calc.Finalize"   <<  std::endl;

	}
};


class  FooCalcTest: public  testing::Test
{
protected :
     virtual   void  SetUp()
    {
	std::cout  <<   "TestCase  FooCalcTest SetUp"   <<  std::endl;
        m_foo.Init();
    }
     virtual   void  TearDown()
    {
	std::cout  <<   "TestCase  FooCalcTest TearDown"   <<  std::endl;
        m_foo.Finalize();
    }

    FooCalc m_foo;
};

TEST_F(FooCalcTest, HandleNoneZeroInput)
{
    EXPECT_EQ( 4 , m_foo.Calc( 12 ,  16 ));
}

TEST_F(FooCalcTest, HandleNoneZeroInput_Error)
{
    EXPECT_EQ( 5 , m_foo.Calc( 12 ,  16 ));
}


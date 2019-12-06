#include <string>
#include <iostream>
#include <iomanip>
#include "Rational.hpp"
#include <cassert>
#include <iostream>
#include <unistd.h>


void check_result(Rational r1, std::string op, Rational r2)
{
	std::cout << r1 << " " << op << " " << r2 << " --> ";
	if (op == "==")
	{
		std::cout << std::boolalpha << (r1 == r2) << std::endl;
	}
}

// Encapsulate all of the Rational tests.
class Test_rational
{
public:
	void default_ctor()
	{
		// Check the default constructor.
		Rational r;
		check_result(r, "==", Rational(0, 1));
		check_result(r, "==", Rational(0, 2));
	}

//Works down to here

  void integer_ctor()
	{
		Rational r(3);
        assert(r == Rational(3,1));
	}


	void rational_ctor()
	{

		// Check that copies work as expected.
		Rational r(3, 4);
        assert(r == Rational(3,4));
        std::cout<< "Rational Copy Constructor Passed"<<std::endl;
	}

	void equality()
	{
		Rational r1(1, 2);
		Rational r2(2, 4);
		Rational r3(1, 4);
        assert(r1 == r2);
        std::cout<< "Rational Equality OL Passed"<<std::endl;
        assert(r1 != r3);
        std::cout<< "Rational Inequality OL Passed"<<std::endl;
	}

	void ordering()
	{
		Rational r1(1, 4);
		Rational r2(1, 2);
        assert(r1 < r2);
        std::cout << " Rational comparison LT OL passed" << std::endl;
        assert(r2 > r1);
        std::cout << " Rational comparison GT OL passed" << std::endl;
        assert(r1 <= r1);
        std::cout << " Rational comparison LT= OL passed" << std::endl;
        assert(r1 >= r1);
        std::cout << " Rational comparison GT= OL passed" << std::endl;
	}

	void arithmetic()
	{
		Rational r1(1, 2);
		Rational r2(1, 4);
        assert(r1 + r2 == Rational(3, 4));
        std::cout << " Rational addition passed" << std::endl;
        assert(r1 - r2 == Rational(1, 4));
        std::cout << " Rational subtraction passed" << std::endl;
        assert(r1 * r2 == Rational(1, 8));
        std::cout << " Rational multiplication passed" << std::endl;
        assert(r1 / r2 == Rational(2, 1));
        std::cout << " Rational division passed" << std::endl;
	}

void interoperate()
  {
    Rational r1 = 1;
    std::cout  << (r1 == 1) << std::endl; // prints true
    std::cout  << (2 == r1 )<< std::endl; // prints false
    std::cout  << (r1 < 2) << std::endl; // prints true
    std::cout  << (0 < r1) << std::endl; // prints true
    std::cout  << (r1 + 2) << std::endl; // prints 3/1 (or just 3)
  }

void rc()
  {
     // Determine if input is coming from a terminal.
     bool term = isatty(0);

    // This will continue reading until it reaches the end-of-input.
    // If you are using this interactively, type crtl-d to send the
    // end of input character to the terminal.
    while (std::cin)
    {
      Rational r1;
      Rational r2;
      std::string op;

      if (term)
      {
        std::cout << "> ";
      }


      std::cin >> r1 >> op >> r2;
      if (!std::cin)
      {
        break;
      }

      // FIXME: Add all of the other overlaoded operators by adding
      // cases for each of them.
      if (op == "==")
      {
        std::cout << std::boolalpha << (r1 == r2) << '\n';
      }
        else if (op == "!=")
      {
        std::cout << std::boolalpha << (r1 != r2) << '\n';
      }
        else if (op == ">")
      {
        std::cout << std::boolalpha << (r1 > r2) << '\n';
      }
        else if (op == "<=")
      {
        std::cout << std::boolalpha << (r1 <= r2) << '\n';
      }
        else if (op == ">=")
      {
        std::cout << std::boolalpha << (r1 >= r2) << '\n';
      }
        else if (op == "<")
      {
        std::cout << std::boolalpha << (r1 < r2) << '\n';
      }
        else if (op == "+")
      {
        std::cout << (r1 + r2) << '\n';
      }
        else if (op == "*")
      {
        std::cout << (r1 * r2) << '\n';
      }
        else if (op == "/")
      {
        std::cout << (r1 / r2) << '\n';
      }
        else if (op == "-")
      {
        std::cout << (r1 - r2) << '\n';
      }
        else
      {
        std::cerr << "invalid operator: " << op << '\n';
      }
    }

    // If we got to the end of the file without fatal errors,
    // return success.
    if (std::cin.eof())
    {
      return;
    }
    // Otherwise, diagnose errors in input and exit with an error
    // code.
    if (std::cin.fail())
    {
      std::cerr << "input error\n";
      return;
    }
}

	// The test runner for this test class.
	void run()
  {
    default_ctor();
    integer_ctor();
    rational_ctor();
    equality();
    ordering();
    arithmetic();
    interoperate();
    rc();
  }
};



int main()
{
	Test_rational test;
	test.run();
}

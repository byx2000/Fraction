#include <cassert>
#include "Fraction.h"

//±ß½çÌõ¼þ²âÊÔ
void BoundaryTest()
{
    assert(Fraction(0, 1).toString() == "0" && Fraction(0, 1).sign == 1);
	assert(Fraction(0, 2).toString() == "0" && Fraction(0, 2).sign == 1);
	assert(Fraction(0, -1).toString() == "0" && Fraction(0, -1).sign == 1);
	assert(Fraction(0, -2).toString() == "0" && Fraction(0, -2).sign == 1);
	assert(Fraction(1, 1).toString() == "1");
	assert(Fraction(-1, 1).toString() == "-1");
	assert(Fraction(1, -1).toString() == "-1");
	assert(Fraction(-1, -1).toString() == "1");
	assert(Fraction(2, 1).toString() == "2");
	assert(Fraction(-2, 1).toString() == "-2");
	assert(Fraction(2, -1).toString() == "-2");
	assert(Fraction(-2, -1).toString() == "2");
	assert(Fraction(1, 2).toString() == "1/2");
	assert(Fraction(-1, 2).toString() == "-1/2");
	assert(Fraction(1, -2).toString() == "-1/2");
	assert(Fraction(-1, -2).toString() == "1/2");
	assert(Fraction(2, 4).toString() == "1/2");
	assert(Fraction(-2, 4).toString() == "-1/2");
	assert(Fraction(2, -4).toString() == "-1/2");
	assert(Fraction(-2, -4).toString() == "1/2");

	assert(Fraction("0", "1").toString() == "0");
	assert(Fraction("0", "2").toString() == "0");
	assert(Fraction("0", "-1").toString() == "0");
	assert(Fraction("0", "-2").toString() == "0");
	assert(Fraction("1", "1").toString() == "1");
	assert(Fraction("-1", "1").toString() == "-1");
	assert(Fraction("1", "-1").toString() == "-1");
	assert(Fraction("-1", "-1").toString() == "1");
	assert(Fraction("2", "1").toString() == "2");
	assert(Fraction("-2", "1").toString() == "-2");
	assert(Fraction("2", "-1").toString() == "-2");
	assert(Fraction("-2", "-1").toString() == "2");
	assert(Fraction("1", "2").toString() == "1/2");
	assert(Fraction("-1", "2").toString() == "-1/2");
	assert(Fraction("1", "-2").toString() == "-1/2");
	assert(Fraction("-1", "-2").toString() == "1/2");
	assert(Fraction("2", "4").toString() == "1/2");
	assert(Fraction("-2", "4").toString() == "-1/2");
	assert(Fraction("2", "-4").toString() == "-1/2");
	assert(Fraction("-2", "-4").toString() == "1/2");

	assert(Fraction(BigInt("0"), BigInt("1")).toString() == "0");
	assert(Fraction(BigInt("0"), BigInt("2")).toString() == "0");
	assert(Fraction(BigInt("0"), BigInt("-1")).toString() == "0");
	assert(Fraction(BigInt("0"), BigInt("-2")).toString() == "0");
	assert(Fraction(BigInt("1"), BigInt("1")).toString() == "1");
	assert(Fraction(BigInt("-1"), BigInt("1")).toString() == "-1");
	assert(Fraction(BigInt("1"), BigInt("-1")).toString() == "-1");
	assert(Fraction(BigInt("-1"), BigInt("-1")).toString() == "1");
	assert(Fraction(BigInt("2"), BigInt("1")).toString() == "2");
	assert(Fraction(BigInt("-2"), BigInt("1")).toString() == "-2");
	assert(Fraction(BigInt("2"), BigInt("-1")).toString() == "-2");
	assert(Fraction(BigInt("-2"), BigInt("-1")).toString() == "2");
	assert(Fraction(BigInt("1"), BigInt("2")).toString() == "1/2");
	assert(Fraction(BigInt("-1"), BigInt("2")).toString() == "-1/2");
	assert(Fraction(BigInt("1"), BigInt("-2")).toString() == "-1/2");
	assert(Fraction(BigInt("-1"), BigInt("-2")).toString() == "1/2");
	assert(Fraction(BigInt("2"), BigInt("4")).toString() == "1/2");
	assert(Fraction(BigInt("-2"), BigInt("4")).toString() == "-1/2");
	assert(Fraction(BigInt("2"), BigInt("-4")).toString() == "-1/2");
	assert(Fraction(BigInt("-2"), BigInt("-4")).toString() == "1/2");

	assert(Fraction("0") == Fraction(0, 1));
	assert(Fraction("0") == Fraction(0, 2));
	assert(Fraction("12") == Fraction(12, 1));
	assert(Fraction("0/1") == Fraction(0, 1));
	assert(Fraction("0/2") == Fraction(0, 1));
	assert(Fraction("1/2") == Fraction(1, 2));
	assert(Fraction("-1/2") == Fraction(-1, 2));
	assert(Fraction("1/-2") == Fraction(-1, 2));
	assert(Fraction("123/57") == Fraction(123, 57));

	assert(Fraction(0, 1) == Fraction(0, 1));
	assert(Fraction(0, 1) == Fraction(0, 2));
	assert(Fraction(0, -2) == Fraction(0, 213123));
	assert(Fraction(1, 2) == Fraction(2, 4));
	assert(Fraction(1, 2) == Fraction(2375427, 4750854));
	assert(Fraction(1, 2) == Fraction(-1, -2));
	assert(Fraction(1, -2) == Fraction(-1, 2));

	assert(Fraction(0, -1) != Fraction(1, 5));
	assert(Fraction(1, 2) != Fraction(2, 2));
	assert(Fraction(1, 2) != Fraction(-1, 2));
	assert(!(Fraction(0, 1) != Fraction(0, 2)));
	assert(!(Fraction(1, 2) != Fraction(2, 4)));
	assert(!(Fraction(-3, 5) != Fraction(3, -5)));

	assert(Fraction(1, 2) < Fraction(1, 1));
	assert(Fraction(-1, 2) < Fraction(1, 1));
	assert(Fraction(1, 3) < Fraction(1, 1));
	assert(Fraction(122, 123) < Fraction(123, 124));
	assert(Fraction(123, -124) < Fraction(-122, 123));
	assert(Fraction(-4, 3) < Fraction(1, 1));
	assert(!(Fraction(0, 1) < Fraction(0, 2)));
	assert(!(Fraction(0, -1) < Fraction(0, 2)));
	assert(!(Fraction(1, 2) < Fraction(1, 2)));
	assert(!(Fraction(-3, 5) < Fraction(3, -5)));
	assert(!(Fraction(3, 2) < Fraction(1, 2)));
	assert(!(Fraction(-3, 2) < Fraction(-4, 2)));

	assert(!(Fraction(1, 2) > Fraction(1, 1)));
	assert(!(Fraction(-1, 2) > Fraction(1, 1)));
	assert(!(Fraction(1, 3) > Fraction(1, 1)));
	assert(!(Fraction(122, 123) > Fraction(123, 124)));
	assert(!(Fraction(123, -124) > Fraction(-122, 123)));
	assert(!(Fraction(-4, 3) > Fraction(1, 1)));
	assert(!(Fraction(1, 2) > Fraction(1, 2)));
	assert(!(Fraction(-3, 5) > Fraction(3, -5)));
	assert(Fraction(2, 5) > Fraction(-1, 3));
	assert(Fraction(3, 2) > Fraction(1, 2));
	assert(Fraction(-3, 2) > Fraction(-4, 2));

	assert((Fraction(0, 1) + Fraction(0, 1)).toString() == "0");
	assert((Fraction(0, -1) + Fraction(0, 5)).toString() == "0");
	assert((Fraction(1, 1) + Fraction(0, 1)).toString() == "1");
	assert((Fraction(1, -1) + Fraction(0, 1)).toString() == "-1");
	assert((Fraction(1, 1) + Fraction(1, 1)).toString() == "2");
	assert((Fraction(-1, 1) + Fraction(-1, 1)).toString() == "-2");
	assert((Fraction(-1, 1) + Fraction(1, 1)).toString() == "0");
	assert((Fraction(1, 2) + Fraction(1, 2)).toString() == "1");
	assert((Fraction(1, 2) + Fraction(1, 3)).toString() == "5/6");
	assert((Fraction(1, 2) + Fraction(-1, 3)).toString() == "1/6");
	assert((Fraction(-1, 2) + Fraction(1, 3)).toString() == "-1/6");
	assert((Fraction(-1, 2) + Fraction(-1, 3)).toString() == "-5/6");
	assert((Fraction(1, 2) + Fraction(1, 2)).toString() == "1");
	assert((Fraction(5, 6) + Fraction(1, 6)).toString() == "1");
	assert((Fraction(7, 6) + Fraction(5, 6)).toString() == "2");
	assert((Fraction(5, 6) + Fraction(-5, 6)).toString() == "0");
	assert((Fraction(7, 6) + Fraction(-1, 6)).toString() == "1");

	assert((Fraction(0, 1) - Fraction(0, 1)).toString() == "0");
	assert((Fraction(0, 1) - Fraction(1, 1)).toString() == "-1");
	assert((Fraction(0, -1) - Fraction(0, 5)).toString() == "0");
	assert((Fraction(1, 1) - Fraction(0, 1)).toString() == "1");
	assert((Fraction(1, -1) - Fraction(0, 1)).toString() == "-1");
	assert((Fraction(1, 1) - Fraction(1, 1)).toString() == "0");
	assert((Fraction(-1, 1) - Fraction(-1, 1)).toString() == "0");
	assert((Fraction(-1, 1) - Fraction(1, 1)).toString() == "-2");
	assert((Fraction(1, 2) - Fraction(-1, 2)).toString() == "1");
	assert((Fraction(1, 2) - Fraction(1, 3)).toString() == "1/6");
	assert((Fraction(1, 2) - Fraction(-1, 3)).toString() == "5/6");
	assert((Fraction(-1, 2) - Fraction(1, 3)).toString() == "-5/6");
	assert((Fraction(-1, 2) - Fraction(-1, 3)).toString() == "-1/6");

	assert((Fraction(0, 1) * Fraction(0, 2)).toString() == "0");
	assert((Fraction(1, 2) * Fraction(0, 1)).toString() == "0");
	assert((Fraction(1, 2) * Fraction(1, 3)).toString() == "1/6");
	assert((Fraction(-1, 2) * Fraction(1, 3)).toString() == "-1/6");
	assert((Fraction(1, 2) * Fraction(1, -3)).toString() == "-1/6");
	assert((Fraction(-1, 2) * Fraction(-1, 3)).toString() == "1/6");
	assert((Fraction(2, 3) * Fraction(3, 2)).toString() == "1");
	assert((Fraction(2, -3) * Fraction(3, 2)).toString() == "-1");
	assert((Fraction(-2, 3) * Fraction(-3, 2)).toString() == "1");
	assert((Fraction(2, 3) * Fraction(3, 4)).toString() == "1/2");
	assert((Fraction(2, -3) * Fraction(3, 4)).toString() == "-1/2");
	assert((Fraction(2, 3) * Fraction(-3, 4)).toString() == "-1/2");
	assert((Fraction(-2, -3) * Fraction(-3, -4)).toString() == "1/2");
	assert((Fraction(2, 3) * Fraction(3, 4)).toString() == "1/2");

	assert((Fraction(0, 1) * Fraction(1, 2)).toString() == "0");
	assert((Fraction(0, 1) * Fraction(-2131, 9870)).toString() == "0");
	assert((Fraction(1, 1) * Fraction(1, 1)).toString() == "1");
	assert((Fraction(-1, 1) * Fraction(1, 1)).toString() == "-1");
	assert((Fraction(1, -1) * Fraction(-1, 1)).toString() == "1");

	assert((Fraction(0, 2) ^ BigInt(1)).toString() == "0");
	assert((Fraction(0, 1) ^ BigInt(5)).toString() == "0");
	assert((Fraction(1, 2) ^ BigInt(0)).toString() == "1");
	assert((Fraction(1, 2) ^ BigInt(1)).toString() == "1/2");
	assert((Fraction(1, 1) ^ BigInt(0)).toString() == "1");
	assert((Fraction(1, 1) ^ BigInt(2)).toString() == "1");
	assert((Fraction(-1, 1) ^ BigInt(1)).toString() == "-1");
	assert((Fraction(-1, 1) ^ BigInt(2)).toString() == "1");
	assert((Fraction(-1, -1) ^ BigInt(3)).toString() == "1");
	assert((Fraction(1, 2) ^ BigInt(2)).toString() == "1/4");
	assert((Fraction(-1, 2) ^ BigInt(2)).toString() == "1/4");
}

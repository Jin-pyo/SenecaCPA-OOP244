// TODO: insert header files

// TODO: continue the namespace

	// TODO: implement the default constructor

	// TODO: implement the two-argument constructor

	// TODO: implement the max query

    // TODO: implement the min query

	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier

    // TODO: implement the display query

    // TODO: implement the isEmpty query

    // TODO: implement the + operator

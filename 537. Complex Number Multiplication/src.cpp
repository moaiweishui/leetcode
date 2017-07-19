class Solution {
public:
    int str2int(string s)
    {
        stringstream ss;
	    int res;
	    ss << s;
	    ss >> res;
	    return res;
    }
    
    string complexNumberMultiply(string a, string b) {
        
        string a_re, a_im, b_re, b_im;
	
	    a_re = a.substr(0, a.find('+'));
	    a_im = a.substr(a.find('+') + 1);
	    b_re = b.substr(0, b.find('+'));
	    b_im = b.substr(b.find('+') + 1);

	    if (a_im == "i")
		    a_im = "1";
	    else if (a_im == "-i")
		    a_im = "-1";
	    else
		    a_im = a_im.replace(a_im.find('i'), 1, "*1");

	    if (b_im == "i")
		    b_im = "1";
	    else if (b_im == "-i")
		    b_im = "-1";
	    else
		    b_im = b_im.replace(b_im.find('i'), 1, "*1");
        
        int a_re_d, a_im_d, b_re_d, b_im_d;
	    a_re_d = str2int(a_re);
	    a_im_d = str2int(a_im);
	    b_re_d = str2int(b_re);
	    b_im_d = str2int(b_im);

	    cout << a_re_d << "+" << a_im_d << endl;
	    cout << b_re_d << "+" << b_im_d << endl;

	    int res_re = a_re_d * b_re_d - a_im_d * b_im_d;
	    int res_im = a_re_d * b_im_d + a_im_d * b_re_d;

	    stringstream ss;
	    if (res_im == 1)
		    ss << res_re << "+i";
	    else if (res_im == -1)
		    ss << res_re << "+-i";
	    else
		    ss << res_re << "+" << res_im << "i";

	    string res;
	    ss >> res;
        return res;
    }
};

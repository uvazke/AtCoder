#include<iostream>
#include<algorithm>
using namespace std;

int sigma(int a, int b){
	return (b*(b+1) - a*(a-1))/2;
}

int main(){
	int R,G,B;
	cin >> R >> G >> B;
	int r1,r2,g1,g2,b1,b2,r,g,b;
	bool flag = true;
	r1 = R/2;
	r2 = R/2 - (1 - R%2);
	g1 = G/2 - (1 - G%2);
	g2 = G/2;
	b1 = B/2 - (1 - B%2);
	b2 = B/2;
	if(r2 + g1 < 100 && g2 + b1 < 100){
		r = sigma(1,r1) + sigma(1,r2);
		g = sigma(1,g1) + sigma(1,g2);
		b = sigma(1,b1) + sigma(1,b2);
	}else{
		if(r2 + g1 >= 100)r2 = 99 - g1;
		if(g2 + b1 >= 100)b1 = 99 - g2;
		if(r2 < 0){
			r1 = abs(r2) - 1 + R;
		}
		if(b1 < 0){
			b2 = abs(b1) - 1 + B;
		}
		while(flag){
			if(abs(r1 - b2) <= 1){
				while(flag){
					int rr,gg,bb;
					//cout << r1<< " " << r2 << " " << g1 << " " << g2 << " " << b1 << " " << b2 << endl;
					if(r2 < 0){
						r = sigma(abs(r2), r1);
					}else{
						r = sigma(1,r1) + sigma(1,r2);
					}
					if(b1 < 0){
						b = sigma(abs(b1), b2);
					}else{
						b = sigma(1,b1) + sigma(1,b2);
					}
					g = sigma(1,g1) + sigma(1,g2);
					if(r2>0){
						if(g2 + b1 == 99){	
							if(r2 + g1 == 99){
								r1 += 1;
								r2 -= 1;
							}
							g1 += 1;
							g2 -= 1;
						}
						b1 += 1;
						b2 -= 1;
					}else{
						if (r2 + g1 == 99){
							if(g2 + b1 == 99){
								b1 -= 1;
								b2 += 1;
							}
							g1 -= 1;
							g2 += 1;
						}
						r1 -= 1;
						r2 += 1;
					}
					if(r2 < 0){
						rr = sigma(abs(r2), r1);
					}else{
						rr = sigma(1,r1) + sigma(1,r2);
					}
					if(b1 < 0){
						bb = sigma(abs(b1), b2);
					}else{
						bb = sigma(1,b1) + sigma(1,b2);
					}
					gg = sigma(1,g1) + sigma(1,g2);
					if(rr + gg + bb >= r + g + b){
						flag = false;
					}
				}
			}else if(r1 == max(max(r1,g2),b2) && r1 > max(g1,g2) + 1){
				if (r2 + g1 == 99){
					if(g2 + b1 == 99){
						b1 -= 1;
						b2 += 1;
					}
					g1 -= 1;
					g2 += 1;
				}
				r1 -= 1;
				r2 += 1;
			}else if(b2 == max(max(r1,g2),b2) && b2 > max(g1,g2) + 1){
				if(g2 + b1 == 99){	
					if(r2 + g1 == 99){
						r1 += 1;
						r2 -= 1;
					}
					g1 += 1;
					g2 -= 1;
				}
				b1 += 1;
				b2 -= 1;
			}else{
				if(r2 < 0){
					r = sigma(abs(r2), r1);
				}else{
					r = sigma(1,r1) + sigma(1,r2);
				}
				if(b1 < 0){
					b = sigma(abs(b1), b2);
				}else{
					b = sigma(1,b1) + sigma(1,b2);
				}
				g = sigma(1,g1) + sigma(1,g2);
				flag = false;	
			}
		}
		//cout << r1<< " " << r2 << " " << g1 << " " << g2 << " " << b1 << " " << b2 << endl;
	}
	cout << r + g + b<< endl;
	return 0;
}
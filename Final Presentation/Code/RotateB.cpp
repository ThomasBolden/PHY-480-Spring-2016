	double A_ik;
	double A_il;
	double B_ik;
	double B_il;
	double A_kk = A(k,k);
	double A_ll = A(l,l);

	A(k,k) = A_kk*cosine*cosine - 2*A(k,l)*cosine*sine 
			 + A_ll*sine*sine;
	A(l,l) = A_ll*cosine*cosine + 2*A(k,l)*cosine*sine 
			 + A_kk*sine*sine; 
	A(k,l) = 0.0;
	A(l,k) = 0.0;
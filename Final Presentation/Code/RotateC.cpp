for (int i = 0; i < n; i++){
		if (i != k && i != l){

			A_ik = A(i,k);
			A_il = A(i,l);
			A(i,k) = A_ik*cosine - A_il*sine; 
			A(k,i) = A(i,k);
			A(i,l) = A_il*cosine + A_ik*sine; 
			A(l,i) = A(i,l);
		}
		B_ik = B(i,k);
		B_il = B(i,l);
		B(i,k) = B_ik*cosine - B_il*sine;
		B(i,l) = B_il*cosine + B_ik*sine; 

	} return; }
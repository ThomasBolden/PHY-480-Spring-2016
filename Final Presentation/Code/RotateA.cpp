void Rotate(mat &A, mat &B, int k, int l, int n){

	double t, tau, sine, cosine;

	if ( A(k,l) != 0.0){
		tau = ( A(l,l) - A(k,k) )/( 2*A(k,l) );
		if (tau >= 0.0) { 
			t = 1.0/(fabs(tau) + sqrt(1.0 + tau*tau)); 
		} 
		else { 	
			t = -1.0/(fabs(tau) + sqrt(1.0 + tau*tau)); 
		}
		cosine = 1.0/ sqrt (1.0 + t*t);
		sine = t*cosine; 
	}
	else {sine = 1.0; cosine = 0.0;}
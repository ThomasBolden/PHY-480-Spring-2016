double MaxOffDiagonal(mat A, int *k, int *l, int n){

	double maxOD;
	double a_ij;

	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			a_ij = fabs(A(i,j));
			if (a_ij > maxOD){
				maxOD = a_ij;
				*k = i;
				*l = j;
			}
		}
	}
	return maxOD;
}
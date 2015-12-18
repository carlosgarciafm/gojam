#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *ifile, *ofile;
	char *iroute = "A-large-practice.in";
	char *oroute = "large-output.out";
	ifile = fopen(iroute,"r");
	ofile = fopen(oroute,"w");

	/* Read the number of cases. */
	int N, n;
	fscanf(ifile, "%d", &N);

	for(n = 0; n < N; n++) {
		int C, P;
		/* Read the amount of credit. */
		fscanf(ifile, "%d", &C);
		/* Read the number of products. */
		fscanf(ifile, "%d", &P);

		/* Put all the prices in the list. */
		int L[P], i;
		for(i = 0; i < P; i++)
			fscanf(ifile, "%d", &L[i]);

		/* Do pick two items. */
		int a, b, A = 0, B = 0;		// I might delete A and B escaping both for loops.
		for(a = 0; a < P; a++)
			for(b = P - 1; b > a; b--)
				if(L[a] + L[b] == C)
					A = a, B = b;

		/* Do write those items with the proper format. */
		fprintf(ofile, "Case #%d: %d %d\n", (n + 1), (A + 1), (B + 1));
	}

	fclose(ifile);
	fclose(ofile);
	return 0;
}

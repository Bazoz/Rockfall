#include "Header.h"
#include "AllegroView.h"


void main()
{
	



		try
		{
			AllegroView all;
			all.Initialize(758, 530, 1, 1, 1);

		}
		catch (char *massage)
		{
			cout << massage << endl;
		}
		catch (int code)
		{
			if (code == 1) cout << "Display creation error!" << endl;
		}
		catch (...)
		{
			cout << "Unknow exception!" << endl;
		}





}
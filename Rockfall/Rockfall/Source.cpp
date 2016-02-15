#include "Header.h"
#include "AllegroView.h"


void main()
{
	



		try
		{
			AllegroView all;
			all.Initialize(383,680);

			all.StartGame();

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
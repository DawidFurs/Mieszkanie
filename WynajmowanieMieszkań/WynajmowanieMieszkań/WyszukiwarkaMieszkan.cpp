#include "WyszukiwarkaMieszkan.h"

WyszukiwarkaMieszkan::WyszukiwarkaMieszkan(Miejscowosc* miejscowosc) : miejscowosc(miejscowosc)
{
}

void WyszukiwarkaMieszkan::wyszukajPoCenie(int limit)
{
	Miejscowosc* wsk = miejscowosc;
	while (wsk != nullptr)
	{
		for (auto& s : wsk->bloki)
		{
			for(auto& p: s.mieszkania)
			{
				for (auto& c : p.ceny | std::views::filter([limit](Cena& c) { return c.getCena() < limit;  }))
				{
					cout << "Blok: " << s.nazwa << " Mieszkanie: " << p.metraz << " " << p.IloscPokoi << " " <<  p.KtorePietro << " " << c << endl;
				}
			}
		}
		wsk = wsk->getNext();
	}
}
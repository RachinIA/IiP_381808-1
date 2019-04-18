#include "SongWriter.h"



SongWriter::SongWriter()
{
	Length = ValidLength = Delta = 0;
	song = nullptr;
}



SongWriter::SongWriter(int l, int x) 
{
	Delta = x;
	ValidLength = l;
	Length = l + x;
	song = new Song[Length];

}

SongWriter::SongWriter(const SongWriter& c)
{
	Length = c.Length;
	ValidLength = c.ValidLength;
	Delta = c.Delta;
	song = new Song[Length];
	for (int i = 0; i < ValidLength; i++)
	{
		song[i] = c.song[i];
	}

}


SongWriter::~SongWriter()
{
	Length = ValidLength = Delta = 0;
	delete[]song;
	song = nullptr;
}

void SongWriter::SortWriter(Song *Songs, int R)
{
	int i = 0, j = R - 1;
	Song S1 = Songs[(i + j) / 2];
	Song S2;

	do {
		while (Songs[i] < S1) i++;
		while (Songs[j] > S1) j--;

		if (i <= j) {
			if (Songs[i] > Songs[j])
			{
				S2 = Songs[i];
				Songs[i] = Songs[j];
				Songs[j] = S2;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < R)
		SortWriter((Songs + i), R - i);
	if (0 < j)
		SortWriter(Songs, j + 1);
}

void SongWriter::AddSong(const Song& c)
{
	if (Length != ValidLength)
	{
		int i = 0;
		while ((c.CheckT()>(song[i].CheckT()) && i < ValidLength)) i++;
		for (int j = ValidLength; j > i; j--)
		{
			song[j] = song[j - 1];
		}
		song[i] = c;
		ValidLength++;
	}
	else
	{
		SongWriter S(Length + Delta, Delta);
		S.ValidLength = Length;

		int i = 0;
		while (c.CheckT() > song[i].CheckT()) i++;

		for (int j = 0; j < i; j++)
		{
			S.song[j] = this->song[j];
		}
		S.song[i] = c;
		for (int j = i + 1; j < ValidLength + 1; j++)
		{
			S.song[j] = this->song[j];
		}
		S.ValidLength++;
		*this = S;
	}

}

void SongWriter::Change(string& _T, string& _Poet, string& _Composer, string& _Executor, string& _Album, Date _d)
{ 
	for (int i = 0; i < ValidLength; i++)
	{
		if (song[i].CheckT() == _T)
		{
			song[i] = Song(_T, _Poet, _Composer, _Executor, _Album, _d);
			
		}
	}
}


void SongWriter:: Search(string& _Title, string& _Executor)
{
	int b = 0;
	for (int i = 0; i < ValidLength; i++)
	{
		if ((song[i].CheckT() == _Title) && (song[i].CheckE() == _Executor))
		{
			if(b==0)
			cout << song[i];
			b++;
		}
	}
	if (b == 0) cout << "Песни с таким названием и исполнителем нет в списках" << endl;
}

bool SongWriter::CheckFromTitle(string& _Title)
{
	for (int i = 0; i < ValidLength; i++)
	{
		if (song[i].CheckT() == _Title)
		{
			 
			 return true;
		}
	}
	return false;
}


void SongWriter::CheckFromPoet(string& _Poet)
{
	int b = 0;
	for (int i = 0; i < ValidLength; i++)
	{
		if (song[i].CheckP() == _Poet)
		{
			cout << song[i] << endl;
			b++;
		}
	}
	if (b == 0) cout << "Песен данного поэта нет в списках" << endl;
}

void SongWriter::CheckFromComposer(string& _Composer)
{
	int b = 0;
	for (int i = 0; i < ValidLength; i++)
	{
		if (song[i].CheckC() == _Composer)
		{
			cout << song[i] << endl;
			b++;
		}
	}
	if (b == 0) cout << "Песен данного композитора нет в списках" << endl;
}

void SongWriter::CheckFromExecutor(string& _Executor)
{
	int b = 0;
	for (int i = 0; i < ValidLength; i++)
	{
		if (song[i].CheckC() == _Executor)
		{
			cout << song[i] << endl;
			b++;
		}
	}
	if (b == 0) cout << "Песен данного исполнителя нет в списках" << endl;
}

int SongWriter::CheckValue()
{
	return ValidLength;
}

void SongWriter::Delete(string& _Title)
{
	for (int i = 0; i < ValidLength; i++)
	{
		if (song[i].CheckT() == _Title)
		{
			for (int j = i; j < ValidLength; j++)
			{
				song[j] = song[j + 1];
			}
			song[ValidLength - 1].SetT("");
			song[ValidLength - 1].SetP("");
			song[ValidLength - 1].SetC("");
			song[ValidLength - 1].SetE("");
			song[ValidLength - 1].SetA("");
			Date _d = { 0,0,0 };
			song[ValidLength - 1].Setd(_d);

			ValidLength--;
		}
	}
}

ostream& operator<<(ostream& stream, const SongWriter& c)
{
	stream << c.ValidLength << endl;
	stream << c.Delta << endl;

	for (int i = 0; i < c.ValidLength; i++)
		stream << c.song[i] << endl;
	return stream;
}
istream& operator>>(istream& stream, SongWriter& c)
{
	
	int L,o;
	stream >> L;
	stream >> o;
	if (L != c.ValidLength)
	{
		delete[] c.song;
		c.ValidLength = L;
		c.Delta = o;

		c.Length = c.ValidLength + c.Delta;
		c.song = new Song[c.Length];
	}
	for (int i = 0; i < c.ValidLength; i++)
	{
		stream >> c.song[i];
	}
	return stream;
}

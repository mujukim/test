#include <set>
#define CATEGORY_NUM 5
#define RANK_MAX 5
typedef struct ResultST
{
	int mID[3];
};

typedef struct DataST
{
	int ID;
	int Rank;
	int category;
};


void init();
int add(int mGoodsID, int mCatagory, int mRank);
int remove(int mGoodsID);
int changeRank(int mGoodsID, int mRank);
int SwapRank(int category, int mRank1, int mRank2);
ResultST GetTopRanks();

struct compare {
	bool operator()(DataST a, DataST b) const
	{
		if (a.Rank < b.Rank) return true;
		else if (a.Rank == b.Rank && a.ID < b.ID) return true;
		else
			return false;
	}
};

std::set<DataST, compare> DataSet[CATEGORY_NUM+1][RANK_MAX+1];
std::set<DataST, compare> TotalSet;

void init()
{
	for (int i = 1; i < CATEGORY_NUM + 1; i++)
	{
		for (int j = 1; j < RANK_MAX + 1; j++)
		{
			DataSet[i][j].clear();
		}
	}
	TotalSet.clear();
}
int add(int mGoodsID, int mCatagory, int mRank)
{
	DataST data;
	int retval = 0;
	data.ID = mGoodsID;
	data.Rank = mRank;
	data.category = mCatagory;
	DataSet[mCatagory][mRank].insert(data);
	TotalSet.insert(data);
	
	for (int i = 1; i < RANK_MAX + 1; i++)
	{
		retval += DataSet[mCatagory][i].size();
	}

	return retval;
}
int remove(int mGoodsID)
{
	int retval = 0;
	auto it = TotalSet.find(mGoodsID);
	for (int i = 1; i < RANK_MAX + 1; i++)
	{
		retval += DataSet[mCatagory][i].size();
	}
	return retval;
}
int changeRank(int mGoodsID, int mRank)
{

}
int SwapRank(int category, int mRank1, int mRank2);
ResultST GetTopRanks();

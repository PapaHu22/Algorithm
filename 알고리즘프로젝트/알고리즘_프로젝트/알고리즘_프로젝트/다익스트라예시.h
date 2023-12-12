//1STAGE
GraphType g = { 3,
	{{ 0, 2, INF },//주인공부터 적1에게는 2의 거리, 적1부터 적2까지는 INF(4)
	{ 2, 0, 2 },
	{ INF, 2, 0 },
	};



//2STAGE FIRST
GraphType g = { 6,
	{{ 0, 2, 2, INF, INF, INF },
	{ 2, 0, INF, 2, INF, INF },
	{ 2, INF, 0, INF, 2, INF },
	{ INF, 2, INF, 0, INF, 2 },
	{ INF, INF, 2, INF, 0, INF },
	{ INF, INF, INF, INF, 2, 0 },
	};



//2STAGE SECOND
GraphType g = { 6,
	{{ 0, 2, 2, INF, INF, INF },
	{ 2, 0, INF, 2, 2, INF },
	{ 2, INF, 0, INF, INF, INF },
	{ INF, 2, INF, 0, INF, 2 },
	{ INF, 2, INF, INF, 0, 2 },
	{ INF, INF, INF, 2, 2, 0 },
	};


//3STAGE FIRST
GraphType g = { 7,
	{{ 0, 2, 2, INF, INF, INF, INF },
	{ 2, 0, INF, 2, 2, INF, INF },
	{ 2, INF, 0, INF, INF, INF, INF },
	{ INF, 2, INF, 0, 2, 2, INF },
	{ INF, 2, INF, INF, 0, INF, INF },
	{ INF, INF, INF, 2, INF, 0, 2 },
	{ INF, INF, INF, INF, INF, 2, 0 },
	};



//3STAGE SECOND
GraphType g = { 7,
	{{ 0, 2, INF, INF, INF, INF, INF },
	{ 2, 0, 2, INF, INF, INF, INF },
	{ INF, 2, 0, 2, 2, INF, INF },
	{ INF, INF, 2, 0, INF, 2, 2 },
	{ INF, INF, 2, INF, 0, INF, INF },
	{ INF, INF, INF, 2, INF, 0, INF },
	{ INF, INF, INF, 2, INF, INF, 0 },
	};



//3STAGE THIRD
GraphType g = { 7,
	{{ 0, 2, INF, INF, INF, INF, INF },
	{ 2, 0, 2, 2, INF, INF, INF },
	{ INF, 2, 0, INF, 2, 2, INF },
	{ INF, 2, INF, 0, INF, INF, INF },
	{ INF, INF, 2, INF, 0, INF, 2 },
	{ INF, INF, 2, INF, INF, 0, 2 },
	{ INF, INF, INF, INF, 2, 2, 0 },
	};



//4STAGE FIRST
GraphType g = { 8,
	{{ 0, 2, INF, INF, INF, INF, INF, INF },
	{ 2, 0, 2, 2, 2, INF, INF, INF },
	{ INF, 2, 0, INF, INF, 2, INF, INF },
	{ INF, 2, INF, 0, INF, INF, INF, INF },
	{ INF, 2, INF, INF, 0, 2, INF, INF },
	{ INF, INF, 2, INF, 2, 0, 2, 2 },
	{ INF, INF, INF, INF, INF, 2, 0, INF },
	{ INF, INF, INF, INF, INF, 2, INF, 0 },
	};



//4STAGE SECOND
GraphType g = { 8,
	{{ 0, 2, 2, INF, INF, INF, INF, INF },
	{ 2, 0, INF, 2, INF, INF, INF, INF },
	{ 2, INF, 0, INF, 2, INF, INF, INF },
	{ INF, 2, INF, 0, INF, 2, INF, INF },
	{ INF, INF, 2, INF, 0, INF, 2, INF },
	{ INF, INF, INF, 2, INF, 0, INF, 2 },
	{ INF, INF, INF, INF, 2, INF, 0, 2 },
	{ INF, INF, INF, INF, INF, 2, 2, 0 },
	};


//4STAGE THIRD
GraphType g = { 8,
	{{ 0, 2, INF, INF, INF, INF, INF, INF },
	{ 2, 0, 2, 2, 2, 2, INF, INF },
	{ INF, 2, 0, INF, INF, INF, 2, INF },
	{ INF, 2, INF, 0, INF, INF, INF, INF },
	{ INF, 2, INF, INF, 0, INF, INF, INF },
	{ INF, 2, INF, INF, INF, 0, 2, INF },
	{ INF, INF, 2, INF, INF, 2, 0, 2 },
	{ INF, INF, INF, INF, INF, INF, 2, 0 },
	};



//Boss_STAGE
GraphType g = { 7,
	{{ 0, 2, INF, INF, INF, INF, INF },
	{ 2, 0, 2, INF, INF, INF, INF },
	{ INF, 2, 0, 2, INF, INF, INF },
	{ INF, INF, 2, 0, 2, 2, INF },
	{ INF, INF, INF, 2, 0, INF, 2 },
	{ INF, INF, INF, 2, INF, 0, 2 },
	{ INF, INF, INF, INF, 2, 2, 0 },
	};





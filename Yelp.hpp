#include <memory>
#include <odb/core.hxx>
#include <odb/lazy-ptr.hxx>
#include <set>
#include <string>

#pragma db view
class StarCount{
public:
	int stars;
	int count;
};

#pragma db view query("select top 1 text, last_elapsed_time from sys.dm_exec_query_stats cross apply sys.dm_exec_sql_text(sql_handle) order by last_execution_time desc")
class LastQueryTime{
public:
	std::string text;
	long elapsed_time;
};

// ---------------------------------------------
// No need to change anything above this line
// ---------------------------------------------

//in none of these cases we need constructors cuz 3.2
//cuz we only load



//what are friends and what are transient fields?
//user class
#pragma db object
class user
{
	public:
		#pragma db id auto
		std::string id;
		std::string name;

		//user () {};
};

//review class
#pragma db object
class review
{
	public:
		#pragma db id auto
		std::string id;
		std::string user_id;
		std::string business_id;
		std::string stars;
};

//hours class
#pragma db object
class hours
{
	public:
		#pragma db id auto
		std::string id;
		std::string business_id;
		//#pragma db not null
		std::string hours;

		//hours () {};
};

#pragma db object
class business
{
	public:
		#pragma db id auto
		std::string id;
		//#pragma db not null
		//std::string business_index;
		std::string latitude;
		std::string longitude;
		//hours () {};
};

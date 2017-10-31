#include "student.hpp"
#include "student-odb.hpp"
#include "../src/odb_async_worker.hpp"

oi::odb_async_worker  worker;
void ex_handler(oi::exception ex)
{
  std::cerr << "#### generic handler" << std::endl;
  //:  std::cerr << ex.what() << std::endl;
   // throw ex;
}
void local_handler(oi::exception ex, const student & obj)
{
    std::cerr << "**** local handler" << std::endl;
    std::cerr << ex.what() << std::endl;

   // throw ex;
}
void post_handler(const student & obj)
{
    std::cerr << "**** post handler" << std::endl;
    std::cerr << obj.id << std::endl;

   // throw ex;
}
int main()
{

    oi_database * db;
    db  = new oi_database("HESSAM_TEST", "ht", "10.0.0.117:1521/oracler2");

    oi::odb_worker_param prm;
    prm.max_que_size = 100000000;
    prm.pool_size = 10;
    prm.commit_count = 1;
    prm.commit_timeout = 1;

    std::function<void(oi::exception)> f= & ex_handler;
    std::function<void(oi::exception, const student&)> f2= &local_handler;
    std::function<void(const student&)> f3= &post_handler;

    worker.init(db, prm, f);
    worker.set_local_handler<student>(f2, f3);
//    worker.set_local_handler<student>(f2);


    student st1, st2;
    st1.name = "hessam";
    st2.name = "ali";

    worker.persist<student>(st1);
    worker.persist<student>(st2);

    sleep(4);
    return 0;
}

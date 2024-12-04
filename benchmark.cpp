
#include <iostream>
#include <stdexcept>
#include <string>
#include <format>

#include "eeeeeeeeval.hpp"

#include <time.h>
namespace profiling {
timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}

timespec start()
{
    timespec start_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
    return start_time;
}

timespec stop(timespec start_time)
{
    timespec stop_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop_time);
    timespec elapsed_time = diff(start_time, stop_time);
    
    return elapsed_time;
}

} // namespace profiling


constexpr uint numRuns = 10e7;

int main(int argc, char* argv[]) {

    eeeeeeeeval e;
    
    {
        volatile float arg1 = 1;
        volatile float arg2 = 2;    
        string expr = "+(1,2)";
        cout << endl << "# " << expr << endl;
        e.parse(expr);
        volatile eeeeeeeeval::var_t res=0;
        auto startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = e.eval();
        }
        timespec elapsedTime = profiling::stop(startTime);
        float t1 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "   eeeeeeeeval: " << t1 << "sec" << endl;
        cout <<"            result = " << res << endl;
        
        res=0;
        startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = arg1+arg2;
        }
        
        elapsedTime = profiling::stop(startTime);
        float t2 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "        native: " << t2 << "sec" << endl;
        cout << "            result = " << res << endl;
        cout << "    = " << t1/t2 << "x" << endl;
    }
    {
        volatile float arg1 = 1;
        volatile float arg2 = 2;
        volatile float arg3 = 3;
        volatile float arg4 = 4;
        string expr = "+(*(1,2),/(3, 4))";
        cout << endl << "# " << expr << endl;
        e.parse(expr);
        volatile eeeeeeeeval::var_t res=0;
        auto startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = e.eval();
        }
        timespec elapsedTime = profiling::stop(startTime);
        float t1 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "   eeeeeeeeval: " << t1 << "sec" << endl;
        cout << "           result = " << res << endl;
        
        res=0;
        startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = ((arg1*arg2)+(arg3/arg4));
        }
        
        elapsedTime = profiling::stop(startTime);
        float t2 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "        native: " << t2 << "sec" << endl;
        cout << "            result = " << res << endl;
        cout << "    = " << t1/t2 << "x" << endl;
    }
    {
        volatile float arg1 = 1;
        volatile float arg2 = 2;
        volatile float arg3 = 3;
        volatile float arg4 = 4;
        volatile float arg5 = 5;
        volatile float arg6 = 6;
        volatile float arg7 = 7;
        volatile float arg8 = 8;
        string expr = "-(*(/(1,2),+(3,4)),/(^(5,6),*(7,8)))";
        cout << endl << "# " << expr << endl;
        e.parse(expr);
        volatile eeeeeeeeval::var_t res=0;
        auto startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = e.eval();
        }
        timespec elapsedTime = profiling::stop(startTime);
        float t1 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "   eeeeeeeeval: " << t1 << "sec" << endl;
        cout <<"            result = " << res << endl;
        
        res=0;
        startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = (((arg1/arg2)*(arg3+arg4))-((powf(arg5,arg6))/(arg7*arg8)));
        }
        
        elapsedTime = profiling::stop(startTime);
        float t2 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "        native: " << t2 << "sec" << endl;
        cout << "            result = " << res << endl;
        cout << "    = " << t1/t2 << "x" << endl;
    }    
    {
        volatile float arg1 = 1;
        volatile float arg2 = 2;
        volatile float arg3 = 3;
        volatile float arg4 = 4;
        volatile float arg5 = 5;
        volatile float arg6 = 6;
        volatile float arg7 = 7;
        volatile float arg8 = 8;
        string expr = "+(*(c(1,0),-(2,3)),/(s(4,0),^(5,6)))";
        cout << endl << "# " << expr << endl;
        e.parse(expr);
        volatile eeeeeeeeval::var_t res=0;
        auto startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = e.eval();
        }
        timespec elapsedTime = profiling::stop(startTime);
        float t1 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "   eeeeeeeeval: " << t1 << "sec" << endl;
        cout <<"            result = " << res << endl;
        
        res=0;
        startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = (std::cos(arg1)*(arg2-arg3))+(std::sin(arg4)/powf(arg5, arg6));
        }
        
        elapsedTime = profiling::stop(startTime);
        float t2 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "        native: " << t2 << "sec" << endl;
        cout << "            result = " << res << endl;
        cout << "    = " << t1/t2 << "x" << endl;
    }
    {
        volatile float arg1 = 5;
        volatile float arg2 = 3;
        volatile float arg3 = 2;
        volatile float arg4 = 3;
        volatile float arg5 = 4;
        volatile float arg6 = 8;
        volatile float arg7 = 6;
        volatile float arg8 = 9;
        volatile float arg9 = 3;
        volatile float arg10 = 1;
        volatile float arg11 = 2;
        string expr = "?(>(/(5,3),2),*(+(3,4),-(8,6)),/(-(9,3),+(1,2)))";
        cout << endl << "# " << expr << endl;
        e.parse(expr);
        volatile eeeeeeeeval::var_t res=0;
        auto startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = e.eval();
        }
        timespec elapsedTime = profiling::stop(startTime);
        float t1 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "   eeeeeeeeval: " << t1 << "sec" << endl;
        cout << "           result = " << res << endl;
        
        res=0;
        startTime = profiling::start();
        for (size_t i = 0; i < numRuns; i++)
        {
            res = ((arg1/arg2) > arg3) ? ((arg4+arg5)*(arg6-arg7)) : ((arg8-arg9)/(arg10+arg11));
        }
        
        elapsedTime = profiling::stop(startTime);
        float t2 = (float)elapsedTime.tv_sec + ((float)elapsedTime.tv_nsec) / 1e9f;
        cout << "        native: " << t2 << "sec" << endl;
        cout << "            result = " << res << endl;
        cout << "    = " << t1/t2 << "x" << endl;
    }

    return 0;
}
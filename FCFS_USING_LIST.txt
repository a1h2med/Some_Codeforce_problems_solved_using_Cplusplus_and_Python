using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedList
{
    class FCFS
    {
        public int y = 0, counter = 0 , x=0;
        public List<int> FCFS_parameter;
        public void FCFS(List<int> data, List<int> arrival_time, out List<int> array1, out List<int> array2)      
        {
            array1 = new List<int>(arrival_time.Count);
            array2 = new List<int>(arrival_time.Count);
            for (int i = 0; i < arrival_time.Count(); i++)
                {
                    for (int j = 0; j < arrival_time.Count; j++)
                    {
                        if (j == i)
                            continue;
                        else
                        {
                            if (arrival_time[i] < arrival_time[j])
                            {
                                if (i > j)
                                {
                                    x = data[i];
                                    data[i] = data[j];
                                    data[j] = x;
                                    y = arrival_time[i];
                                    arrival_time[i] = arrival_time[j];
                                    arrival_time[j] = y;
                                    break;
                                }
                                else
                                    continue;
                            }
                            else
                            {
                                if (j > i)
                                {
                                    x = data[i];
                                    data[i] = data[j];
                                    data[j] = x;
                                    y = arrival_time[i];
                                    arrival_time[i] = arrival_time[j];
                                    arrival_time[j] = y;
                                    break;
                                }
                                else continue;
                            }
                        }
                    }
                    if (i == arrival_time.Count - 1)
                    {
                        counter++;
                        if (counter == arrival_time.Count - 1)
                            break;
                        else i = 0;
                    }
                }
                for (int i = 0; i < arrival_time.Count; i++)
                {
                    array1[i] = arrival_time[i];
                    array2[i] = data[i];
                }
            }
        }
    }


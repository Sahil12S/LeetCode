using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class DeviceNameSystem
    {
        public string[] GetUniqueDeviceNames(string[] deviceNames)
        {
            Dictionary<string, int> uniqueDevices = new Dictionary<string, int>();
            List<string> ud = new List<string>();
            foreach (string d in deviceNames)
            {
                if (uniqueDevices.ContainsKey(d))
                {
                    ud.Add(d + (uniqueDevices[d]++).ToString());
                    Console.WriteLine(ud[ud.Count - 1]);
                }
                else
                {
                    uniqueDevices[d] = 1;
                    ud.Add(d);
                    Console.WriteLine(ud[ud.Count - 1]);
                }
            }
            return ud.ToArray();
        }
    }
}

using static System.Net.Mime.MediaTypeNames;

namespace console_net_osgeo_example
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var gj_file = new osgeonetwrapper.OGR_DS_Worker_test("C:\\bicycles.geojson", "GeoJSON");
            if (gj_file.layer_names != null)
            {
                foreach (string layer_name in gj_file.layer_names)
                {
                    Console.WriteLine(layer_name);
                }
            }
            Console.WriteLine("End!");
            Console.ReadKey();
            
        }
    }
}
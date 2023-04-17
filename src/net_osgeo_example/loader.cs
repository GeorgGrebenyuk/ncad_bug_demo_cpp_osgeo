using HostMgd.ApplicationServices;
using System.Runtime.CompilerServices;
using Teigha.Runtime;

namespace net_osgeo_example
{
    public class loader
    {
        [CommandMethod("OGR_RUN_NET")]
        public void test_load()
        {
            var gj_file = new osgeonetwrapper.OGR_DS_Worker_test("C:\\bicycles.geojson", "GeoJSON");
            var doc = Application.DocumentManager.MdiActiveDocument;
            foreach (string layer_name in gj_file.layer_names)
            {
                doc.Editor.WriteMessage(layer_name);
            }
        }
    }
}
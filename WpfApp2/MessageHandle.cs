using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Interop;

namespace WpfApp2
{
    class MessageHandle 
    {
        Panel m_displayPanel;
        MainWindow m_parent;
        public MessageHandle(Panel diplay, MainWindow parent)
        {
            m_displayPanel = diplay;
            
            m_parent = parent;
        }
        public void PreFilterMessage(ref MSG m, ref bool handled)
        {
            if (m.hwnd == m_displayPanel.Handle)
            {
                NativeMethods.WndProc(m_displayPanel.Handle, m.message, m.wParam.ToInt32(), m.wParam.ToInt32());
                handled = true;
            }
            handled = false;
        }

        public void Application_Idle(object sender, EventArgs e)
        {
            try
            {
                // Render the scene if we are idle
                NativeMethods.RenderFrame();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            m_parent.InvalidateVisual();
        }
    }
}

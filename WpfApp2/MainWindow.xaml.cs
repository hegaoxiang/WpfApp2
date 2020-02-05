using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp2
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        IntPtr m_hWnd;
        IntPtr m_displayHandle;
        public MainWindow()
        {
            InitializeComponent();
            IntPtr hInstance = Marshal.GetHINSTANCE(this.GetType().Module);
            m_displayHandle = this.video.Handle;
            
            NativeMethods.EditorMain(hInstance, IntPtr.Zero, m_displayHandle, 10, this.video.Width, this.video.Height);

            MessageHandle message = new MessageHandle(video, this);
            ComponentDispatcher.ThreadIdle += message.Application_Idle;
            ComponentDispatcher.ThreadFilterMessage += message.PreFilterMessage;
            
        }

       
    }
}

import { BrowserRouter} from "react-router-dom";
import { AuthProvider } from "./context/AuthContext";
import AppRoutes from "./Routes/AppRoutes";
import Navbar from "./components/Navbar";

function App() {
  return (
    
    <BrowserRouter>
      <AuthProvider>
        <Navbar/>
        <AppRoutes />
      </AuthProvider>
    </BrowserRouter>
  );
}

export default App;
import { Link, Outlet } from "react-router-dom";
import useAuth from "../hooks/useAuth";

const Navbar = () => {
  const { email, setEmail } = useAuth();

  const handleLogout = () => {
    setEmail(''); 
  };

  return (
    <>
      <nav className="bg-gradient-to-r from-purple-600 to-blue-500 shadow-lg">
        <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
          <div className="flex items-center justify-between h-16">
            <div className="flex items-center space-x-8">
              <Link to="/dashboard" className="text-white font-bold text-xl">
                MyApp
              </Link>
              <Link 
                to="/contact" 
                className="text-white hover:bg-purple-700 px-3 py-2 rounded-md text-sm font-medium transition duration-300"
              >
                Contact
              </Link>
            </div>

            {/* Right side - Auth Section */}
            <div className="flex items-center">
              {email ? (
                <>
                  <span className="text-white text-sm mr-4 hidden md:inline">
                    Welcome, {email}
                  </span>
                  <button
                    onClick={handleLogout}
                    className="bg-white text-purple-600 hover:bg-gray-100 px-4 py-2 rounded-md text-sm font-medium transition duration-300"
                  >
                    Logout
                  </button>
                </>
              ) : (
                <Link
                  to="/signup"
                  className="bg-white text-purple-600 hover:bg-gray-100 px-4 py-2 rounded-md text-sm font-medium transition duration-300"
                >
                  SignUp
                </Link>
              )}
            </div>
          </div>
        </div>
      </nav>
      
     
      <div className="pt-16"> 
        <Outlet />
      </div>
    </>
  );
};

export default Navbar;
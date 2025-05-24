import { Route, Routes } from "react-router-dom";
import Dashboard from "../components/Dashboard";
import Login from "../components/Login";
import ProtectedRoutes from "./ProtectedRoutes";
import Details from "../components/Details";
import Contact from "../components/Contact";

const AppRoutes = () => {
  return (
    <Routes>
      <Route path="login" element={<Login />} />
      <Route path="contact" element={<Contact/>} />
      <Route path="/details/:id" element={<Details/>} />
      <Route
        path="dashboard" 
        element={
          <ProtectedRoutes>
            <Dashboard />
          </ProtectedRoutes>
        }
      />
    </Routes>
  );
};

export default AppRoutes;
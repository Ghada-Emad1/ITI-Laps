
import { useForm } from "react-hook-form";
import useAuth from "../hooks/useAuth";
import { useNavigate } from "react-router-dom";
interface LoginForm{
  email:string
  password:string
}
const Login = () => {
  const{email,setEmail}=useAuth();
  const{register,handleSubmit,formState:{errors}}=useForm<LoginForm>();
  const navigate = useNavigate();

  const onSubmit = (data: LoginForm) => {
    console.log("Form submitted with:", data);
    setEmail(data.email); 
    navigate("/dashboard"); 
  };

  console.log(email)


    return (
      <div className="flex items-center justify-center min-h-[90vh] bg-gradient-to-br from-blue-50 to-purple-50">
        <form onSubmit={handleSubmit(onSubmit)} className="bg-white p-8 rounded-2xl shadow-xl w-full max-w-md">
          <h2 className="text-3xl font-bold text-center text-gray-800 mb-8">Welcome Back</h2>
          
          <div className="mb-6">
            <label htmlFor="email" className="block text-gray-700 text-sm font-medium mb-2">
              Email Address
            </label>
            <input
              {...register("email",{
                required:"Email is required",
                pattern:{
                   value: /^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}$/i,
                message: "Invalid email address"
                }
              })}
              type="email"
              id="email"
              value={email}
              className={`w-full px-4 py-3 rounded-lg border ${
                errors.email ? "border-red-500" : "border-gray-300"
              } focus:outline-none focus:ring-2 focus:ring-purple-500 focus:border-transparent transition-all`}
              placeholder="your@email.com"
              onChange={(e)=>{
                e.preventDefault();
                e.stopPropagation();
                setEmail(e.target.value)
              }
                }
              
            />
            {errors.email && (
            <p className="mt-1 text-sm text-red-600">{errors.email.message}</p>
          )}
          </div>
          
          
          
          <button
            type="submit"
            className="w-full bg-gradient-to-r from-purple-600 to-blue-500 hover:from-purple-700 hover:to-blue-600 text-white font-medium py-3 px-4 rounded-lg shadow-md hover:shadow-lg transition-all duration-300"
          >
            Sign In
          </button>
          
         
          
          
        </form>
      </div>
    );
  };
  
  export default Login;
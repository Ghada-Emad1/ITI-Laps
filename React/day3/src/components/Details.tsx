import { useParams} from "react-router-dom";
import { useState, useEffect } from "react";
import axios from "axios";

interface Post {
  id: number;
  title: string;
  body: string;
}

const BlogDetails = () => {
  const { id } = useParams<{ id: string }>();
  const [post, setPost] = useState<Post | null>(null);

  useEffect(() => {
    axios.get<Post>(`https://jsonplaceholder.typicode.com/posts/${id}`)
      .then(res => {
        setPost(res.data);
      
      })
     
  }, []);

 
  if (!post) return <div className="text-center py-8">Post not found</div>;

  return (
    <div className="max-w-4xl mx-auto p-6 bg-white rounded-xl shadow-lg my-8">
      <h1 className="text-3xl font-bold text-gray-800 mb-4">{post.title}</h1>
      <p className="text-gray-600 text-lg">{post.body}</p>
      
    </div>
  );
};

export default BlogDetails;
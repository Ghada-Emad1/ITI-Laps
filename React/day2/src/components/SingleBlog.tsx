import React from 'react'

const SingleBlog = ({ post, showId }) => {
    return (
      <div className="w-80 bg-white rounded-xl shadow-lg p-4 border border-gray-200 hover:shadow-xl transition duration-300">
        <h2 className="text-xl font-semibold text-gray-800 mb-2">{post.title}</h2>
        <p className="text-gray-600">{post.body}</p>
        <button
          onClick={() => showId(post.id)}
          className="bg-purple-400 px-6 py-2 text-white rounded-xl mt-4"
        >
          Show ID
        </button>
      </div>
    );
  };
  

export default SingleBlog

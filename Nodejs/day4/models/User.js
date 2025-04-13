const mongoose = require("mongoose");

const { Schema } = mongoose;
const schemaOptions = {
  toJSON: {
    virtuals: true,
  },
  toObject: {
    virtuals: true,
  },
};
const userSchema = new Schema(
  {
    name: {
      type: String,
      required: true,
    },
    email: {
      type: String,
      required: true,
      unique: true,
    },
    password: {
      type: String,
      required: true,
    },
    role: {
      type: String,
      enum: ["user", "admin"],
      default: "user",
    },
    fullName: {
      type: String,
      required: true,

    }
  },
  {
    timestamps: true,
  },schemaOptions
);

userSchema.virtual('fullname').get(function () { 
  return ` full name of ${this.name} is ${this.fullName} `;
})



userSchema.virtual("posts", {
  ref: "Post", // The model to use
  localField: "_id", // Find posts where `localField`
  foreignField: "author", // is equal to `foreignField`
  justOne: false, // Set to true if you want a single doc
});
module.exports = mongoose.model('User', userSchema);
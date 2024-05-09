const mongoose = require('mongoose')

const connectDB = async() => {

    try{
        const conn=await mongoose.connect('mongodb+srv://webproject:web%40123@pal.oqj0zct.mongodb.net/game'
    );
        console.log(`MongoDb Connected: ${conn.connection.host}`);
    }
    catch(error){
        console.error(error);
        process.exit(1);
    }
};

module.exports= connectDB;
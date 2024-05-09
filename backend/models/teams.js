const mongoose = require('mongoose');

const teamsSchema = new mongoose.Schema({
    TeamName: String,
    TotalGamesPlayed: String,
    Score: String,
    AvatarName: String,
    ImageName:String,
});

const teamsModel = mongoose.model("teams", teamsSchema);
module.exports = teamsModel;

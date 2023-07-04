# BWS-V2

BWS V2 is not anything but a try to screen out derankers from osu, taking in accountment the badges that have been awarded in the past by applying a **weight** on them.

Currently, osu-api V2 stores the date of badge awarding as date.

The idea is that when doing a screening, during when the program is executed at that time the user processes it, it makes a difference with the badge_date[i] with the date of today.

My formula consist of taking in accountment 4 time spans of one year of all the badge awarded and subdividing them in 4 sets with the following weights and time spans (**WIP**):

    from 0 to 3 months, the weight applied is 0.2;

    from 3 to 6 months, the weight applied is 0.6;

    from 6 to 9 months, the weight applied is 0.9;

    from 9 to inf months, the weight applied is 0.01;


the current formula will look like this:

![BWS-V2](https://cdn.discordapp.com/attachments/1123599284634386553/1123601498010570852/image.png)

I'm currently open to suggestions by applying a **Discussions** on this repository.
-- custom_texts
ALTER TABLE `custom_texts`
    ADD COLUMN `content_loc9` text AFTER `content_loc8`,
    ADD COLUMN `content_loc10` text AFTER `content_loc9`,
    ADD COLUMN `content_loc11` text AFTER `content_loc10`;

-- gossip_texts
ALTER TABLE `gossip_texts`
    ADD COLUMN `content_loc9` text AFTER `content_loc8`,
    ADD COLUMN `content_loc10` text AFTER `content_loc9`,
    ADD COLUMN `content_loc11` text AFTER `content_loc10`;

-- script_texts
ALTER TABLE `script_texts`
    ADD COLUMN `content_loc9` text AFTER `content_loc8`,
    ADD COLUMN `content_loc10` text AFTER `content_loc9`,
    ADD COLUMN `content_loc11` text AFTER `content_loc10`;

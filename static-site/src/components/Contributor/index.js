import React from 'react';
import styles from './styles.module.css';
import { FaGithubSquare } from 'react-icons/fa';
import { GitBranchIcon, GitPullRequestArrowIcon } from 'lucide-react';
const contributors = [
  {
    name: 'Fork the Repository',
    logo: <FaGithubSquare />,
    description: 'Start by forking the repository to your GitHub account. This will allow you to work on your own copy of the project.',
  },
  {
    name: 'Branch',
    logo: <GitBranchIcon />,
    description: 'Once forked, create a new branch for your feature or bug fix. This ensures that your changes can be reviewed independently.',
  },
  {
    name: 'Create a Pull Request',
    logo: <GitPullRequestArrowIcon />,
    description: 'Once your changes are complete, create a pull request to merge your branch back into the main repository. This will notify the maintainers to review your changes.',
  },
];

const Contributor = () => {
  return (
    <div className={styles.contributorSection}>
      <h2>Our Contributors</h2>
      <p>Join us in building an amazing open-source project. Whether you're a seasoned developer or a beginner, we welcome all contributions</p>
      <div className={styles.contributorCards}>
        {contributors.map((contributor, index) => (
          <div key={index} className={styles.contributorCard}>
            {contributor.logo}
            <h3>{contributor.name}</h3>
            <p>{contributor.description}</p>
          </div>
        ))}
      </div>
    </div>
  );
};

export default Contributor;